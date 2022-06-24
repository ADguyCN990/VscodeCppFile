#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
#define mod 998244353
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define pb emplace_back
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int head[MAXN];int tot;
struct EDGE
{
    int to,next;
}edge[MAXM];
void add_edge(int from,int to)
{
    edge[++tot].to=to;edge[tot].next=head[from];head[from]=tot;
}
int n;
ll dp[MAXN];

int dfs(int now, int pre)
{
    int e = 0; //点数
    dp[now] = 1;
    for (int i = head[now]; i; i = edge[i].next)
    {
        int to = edge[i].to;
        if (to == pre) continue;
        int siz = dfs(to, now);
        if (siz % 2 == 0) e ++; //有一条边能空出来
        dp[now] = dp[now] * dp[to] % mod;
    }
    for (int i = 3; i <= e; i += 2) dp[now] = dp[now] * i % mod; //计算多出来的菊花图的贡献
    return e; //返回点数，边数奇偶相反
}

void solve()
{
    n = read();
    for (int i = 1; i < n; i ++)
    {
        int u, v;
        u = read(), v = read();
        add_edge(u ,v), add_edge(v, u);
    }
    dfs(1, -1);
    printf("%lld\n", dp[1]);
}

int main()
{
    solve();
    return 0;
}