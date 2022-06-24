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
ll n, V;
ll v[20];
ll dp[3005];
void solve() {
    n = read(), V = read();
    dp[0] = 1;
    for (int i = 1; i <= n; i++) v[i] = read();
    for (int i = 1; i <= n; i++) {
        for (int j = v[i]; j <= V; j++) {
            dp[j] += dp[j - v[i]];
        }
    }
    printf("%lld\n", dp[V]);
}

int main() {
    solve();
    return 0;
}