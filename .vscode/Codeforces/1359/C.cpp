#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int, int> pii;
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
int H, C, T;
double h, c, t;
double cal(int x) {
    return ((x + 1) * h + x * c + 0.0) / (x + x + 1.0);
}

void solve() {
    H = read(), C = read(), T = read();
    h = H + 0.0, c = C + 0.0, t = T + 0.0;
    int l = 0, r = 1e6;
    if (H + C >= 2 * T) {
        puts("2");
        return;
    }
    while (r - l > 1000) {
        int mid = (l + r) >> 1;
        double tmp = cal(mid);
        if (tmp > t) //温度太高了，多倒点水
            l = mid;
        else //温度太低了，少倒点
            r = mid;
    }
    double dif = INF;
    int ans;
    for (int i = l; i <= r; i++) {
        //倒了2*i+1杯水
        double tmp = fabs(cal(i) - t + 0.0);
        if (tmp < dif) {
            dif = tmp;
            ans = 2 * i + 1;
        }
    }
    printf("%d\n", ans);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}