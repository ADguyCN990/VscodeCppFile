#include<bits/stdc++.h>
using namespace std;
#define MAXN 2005
#define ll long long
#define INF 0x3f3f3f3f
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
ll n, h, l, r, a[MAXN];
ll dp[MAXN][MAXN];

int dfs(int now, int hour) {
    if (now == n + 1) 
        return 0;
    if (dp[now][hour] != -1) 
        return dp[now][hour];
    // a[i]
    int to = (hour + a[now]) % h; 
    int ans1 = (to >= l && to <= r) + dfs(now + 1, to);
    //a[i] - 1
    to = (hour + a[now] - 1) % h;
    int ans2 = (to >= l && to <= r) + dfs(now + 1, to);
    return dp[now][hour] = max(ans1, ans2);
}

int main() {
    n = read(), h = read(), l = read(), r = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    memset(dp, -1, sizeof dp);
    printf("%d\n", dfs(1, 0));
    return 0;
}