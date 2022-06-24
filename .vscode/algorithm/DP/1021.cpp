#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 505
#define MAXM 6005
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
ll n, V;
ll v[MAXN], w[MAXN], s[MAXN];
ll dp[2][MAXM];
ll q[MAXM];
void solve() {
    n = read(), V = read();
    for (int i = 1; i <= n; i++) v[i] = read(), w[i] = read(), s[i] = read();
    for (int i = 1; i <= n; i++) {
        for (int r = 0; r < v[i]; r++) {
            int hh = 1, tt = 0;
            int now = i & 1;
            int pre = (i - 1) & 1;
            for (int j = r; j <= V; j += v[i]) {
                while (hh <= tt && dp[pre][q[tt]] + (j - q[tt]) / v[i] * w[i] <= dp[pre][j])
                    tt--;
                q[++tt] = j;
                while (hh <= tt && (j - q[hh]) / v[i] >= s[i] + 1) 
                    hh++;
                dp[now][j] = dp[pre][q[hh]] + (j - q[hh]) / v[i] * w[i];
            }
        }
    }
    printf("%lld\n", dp[n & 1][V]);
}

int main() {
    solve();
    return 0;
}