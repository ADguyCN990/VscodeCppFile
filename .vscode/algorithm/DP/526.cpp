#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 20
#define MAXM 200005
typedef pair<double, double> pdd;
#define INF 0x3f3f3f3f
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define per(i, x, y) for(int i = x; i >= y; i--)
#define pb emplace_back
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

int seg[MAXN][MAXN]; //所有抛物线杀死猪的情况，1表示被杀死
pdd node[MAXN];
ll dp[1 << MAXN];
int n, m;

int cmp(double a, double b) {
    if (fabs(a - b) < 1e-8) return 0; //相同
    if (a > b) return 1; //a大于b
    if (a < b) return -1; //a小于b
}

void solve() {
    n = read(), m = read();
    for (int i = 0; i < n; i++) scanf("%lf%lf", &node[i].first, &node[i].second);
    memset(seg, 0, sizeof seg);
    for (int i = 0; i < n; i++) {
        seg[i][i] = 1 << i; //一条直线
        for (int j = 0; j < n; j++) {
            //两个点确定一条抛物线
            double x = node[i].first, y = node[i].second;
            double xx = node[j].first, yy = node[j].second;
            double a = (y / x - yy / xx) / (x - xx);
            double b = (y / x - a * x);
            if (cmp(a, 0.0) != -1) continue; //抛物线开口向上，舍去
            for (int k = 0; k < n; k++) {
                double u = node[k].first, v = node[k].second;
                if (cmp(a * u * u + b * u, v) == 0) 
                    seg[i][j] += 1 << k; //能够杀死这头猪
            }

        }
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int st = 0; st < (1 << n) - 1; st++) {
        int pos = -1;
        for (int i = 0; i < n; i++)
            if (!(st >> i & 1))
                pos = i;
        for (int i = 0; i < n; i++) {
            int nxt = seg[pos][i] | st;
            dp[nxt] = min(dp[nxt], dp[st] + 1);
        }
    }
    printf("%lld\n", dp[(1 << n) - 1]);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}