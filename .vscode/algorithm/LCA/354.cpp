#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
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
int n, m;
int depth[MAXN], fa[MAXN][35];
int d[MAXN];
int q[MAXN];
int ans;

void bfs()
{
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[1] = 1;
    int hh = 0, tt = 0;
    q[0] = 1;

    while (hh <= tt)
    {
        int t = q[hh ++ ];
        for (int i = head[t]; i; i = edge[i].next)
        {
            int j = edge[i].to;
            if (depth[j] > depth[t] + 1)
            {
                depth[j] = depth[t] + 1;
                q[ ++ tt] = j;
                fa[j][0] = t;
                for (int k = 1; k <= 16; k ++ )
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
            }
        }
    }

}

int lca(int a, int b)
{
    if (depth[a] < depth[b]) swap(a, b);
    for (int k = 31; k >= 0; k--)
        if (depth[fa[a][k]] >= depth[b])
            a = fa[a][k];
    if (a == b) return a;
    for (int k = 31; k >= 0; k--)
    {
        if (fa[a][k] != fa[b][k])
        {
            a = fa[a][k];
            b = fa[b][k];
        }
    }
    return fa[a][0];
}

int dfs(int now, int pre)
{
    int res = d[now];
    for (int i = head[now]; i; i = edge[i].next)
    {
        int to = edge[i].to;
        if (to == pre) continue;
        int s = dfs(to, now);
        if (s == 0) 
            ans += m;
        else if (s == 1)
            ans ++;
        res += s;
    }
    return res;
}

void solve()
{
    n = read(), m = read();
    for (int i = 1; i < n; i ++)
    {
        int a, b;
        a = read(), b = read();
        add_edge(a,b);
        add_edge(b,a);
    }   
    bfs();
    for (int i = 1; i <= m; i ++)
    {
        int a, b;
        a = read(), b = read();
        int p = lca(a, b);
        d[a] ++, d[b] ++, d[p] -= 2;
    }
    dfs(1, -1);
    printf("%d\n", ans);
}

int main()
{
    solve();
    return 0;
}