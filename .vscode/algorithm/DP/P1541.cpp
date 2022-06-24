#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
#define MAXM 1005
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
ll a[MAXM];
ll dp[45][45][45][45];
int cnt[5];
ll v[MAXN];
ll V, n;
ll dfs(int n1, int n2, int n3, int n4) {
    if (dp[n1][n2][n3][n4]) return dp[n1][n2][n3][n4];
    if (n1 == cnt[1] && n2 == cnt[2] && n3 == cnt[3] && n4 == cnt[4]) return 0; //没地方可走了，return
    int now = n1 * 1 + n2 * 2 + n3 * 3 + n4 * 4 + 1;
    ll ans = 0;
    if (n1 < cnt[1]) {
        ans = max(ans, dfs(n1 + 1, n2, n3, n4) + a[now + 1]);
    }
    if (n2 < cnt[2]) {
        ans = max(ans, dfs(n1, n2 + 1, n3, n4) + a[now + 2]);
    }
    if (n3 < cnt[3]) {
        ans = max(ans, dfs(n1, n2, n3 + 1, n4) + a[now + 3]);
    }
    if (n4 < cnt[4]) {
        ans = max(ans, dfs(n1, n2, n3, n4 + 1) + a[now + 4]);
    }
    return dp[n1][n2][n3][n4] = ans;
}

void solve() {
    V = read(), n = read();
    for (int i = 1; i <= V; i++) a[i] = read();
    for (int i = 1; i <= n; i++) v[i] = read(), cnt[v[i]]++;
    dfs(0, 0, 0, 0);
    printf("%lld\n", dp[0][0][0][0] + a[1]);
}

int main() {
    solve();
    return 0;
}