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
int n, m;
int head[MAXN];int tot;
struct EDGE
{
    int to,next;
}edge[MAXM];
void add_edge(int from,int to)
{
    edge[++tot].to=to;edge[tot].next=head[from];head[from]=tot;
}

int idx = 0, idxx;
pii p[MAXN];
pii pp[MAXN];
int indgr[MAXN];
int order[MAXN], k;
void init()
{
    tot = 0;
    idx = 0;
    idxx = 0;
    k = 0;
    for (int i = 1; i <= n; i ++) head[i] = 0;
    for (int i = 1; i <= n; i ++) indgr[i] = 0;
    for (int i = 1; i <= n; i ++) order[i] = 0;
}

bool topu()
{
    queue <int> q;
    for (int i = 1; i <= n; i ++)
        if (!indgr[i])
            q.push(i), order[i] = ++ k;
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int i = head[now]; i; i = edge[i].next)
        {
            int to = edge[i].to;            
            indgr[to] --;
            if (!indgr[to]) q.push(to), order[to] = ++ k;
        }
    }
    for (int i = 1; i <= n; i ++)
        if (indgr[i])
            return false;
    return true;
}

void solve()
{
    n = read(), m = read();
    init();
    for (int i = 1; i <= m; i ++)
    {
        int opt, u, v;
        opt = read(), u = read(), v = read();
        if (opt == 1)
        {
            add_edge(u, v);
            indgr[v] ++;
            pp[++ idxx] = {u, v};
        }
        else
        {
            p[++ idx] = {u, v};
        }
    }
    bool flag = topu();
    if (!flag)
    {
        puts("NO");
        return;
    }
    puts("YES");
    for (int i = 1; i <= idx; i ++)
    {
        int u = p[i].first, v = p[i].second;
        if (order[u] < order[v])
        {
            printf("%d %d\n", u, v);
        }
        else if (order[u] > order[v])
        {
            printf("%d %d\n", v, u);
        }
    }
    for (int i = 1; i <= idxx; i ++)
        printf("%d %d\n", pp[i].first, pp[i].second);
}

int main()
{
    int T;
    T=read();
    while(T--)
    {
        solve();
    }

    return 0;
}