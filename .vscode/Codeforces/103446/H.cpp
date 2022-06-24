#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 400005
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
int n, m, q;
ll w[MAXN]; //点权
int f[MAXN];
int findx(int x)
{
    if (x == f[x]) return x;
    return f[x] = findx(f[x]);
}
struct node
{
    int u, v, w;
}a[MAXN];
bool cmp(node a, node b) {return a.w < b.w;}
int head[MAXN];int tot;
struct EDGE
{
    int to,next;
}edge[MAXM];
void add_edge(int from,int to)
{
    edge[++tot].to=to;edge[tot].next=head[from];head[from]=tot;
}
//不会写ST表

ll limit[MAXN]; //到达这个点的阈值
ll sum[MAXN]; //子树点权之和
int fa[MAXN][25];
ll mx[MAXN][25]; //x的2^j祖先中，边权减点权的最大值
int cnt;
int rt; 
void kruskal()
{
    sort(a + 1, a + 1 + m, cmp);
    cnt = n;
    for (int i = 1; i <= n; i ++) f[i] = i;
    for (int i = 1; i <= m; i ++)
    {
        if (cnt == 2 * n - 1) break;
        int u = a[i].u, v = a[i].v, w = a[i].w;
        u = findx(u), v = findx(v);
        if (u == v) continue;
        limit[++ cnt] = w;
        f[u] = cnt, f[v] = cnt, f[cnt] = cnt;
        add_edge(cnt, u), add_edge(cnt, v);
    }
    rt = 2 * n - 1;
}

void dfs1(int now) //预处理子树点权值和父亲
{
    if (now <= n)
    {
        sum[now] = w[now];
        return;
    }
    for (int i = head[now]; i; i = edge[i].next)
    {
        int to = edge[i].to;
        fa[to][0] = now;
        dfs1(to);
        sum[now] += sum[to];
    }
}

void dfs2(int now)
{
    mx[now][0] = limit[fa[now][0]] - sum[now];
    for (int i = 1; i <= 23; i ++)
    {
        fa[now][i] = fa[fa[now][i - 1]][i - 1];
        mx[now][i] = max(mx[now][i - 1], mx[fa[now][i - 1]][i - 1]);

    }
    for (int i = head[now]; i; i = edge[i].next)
    {
        int to = edge[i].to;
        dfs2(to);
    }
}

int query(int x, int y)
{
    for (int i = 23; i >= 0; i --)
    {
        if (fa[x][i] && mx[x][i] <= y)
            x = fa[x][i];
    }
    return sum[x];
}

void solve()
{
    n = read(), m = read(), q = read();
    for (int i = 1; i <= n; i ++) w[i] = read();
    for (int i = 1 ; i <= m; i ++)
    {
        int u, v, w;
        a[i].u = read(), a[i].v = read(), a[i].w = read();
    }
    kruskal();
    dfs1(rt);
    dfs2(rt);
    for (int i = 1; i <= q; i ++)
    {
        int x, y;
        x = read(), y = read();
        printf("%d\n", y + query(x, y));
    }
}

int main()
{
    solve();
    return 0;
}