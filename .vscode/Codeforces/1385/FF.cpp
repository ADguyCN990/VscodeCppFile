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
int n, k;
int d[MAXN];
int leaf[MAXN];
int head[MAXN];int tot;
struct EDGE
{
    int to,next;
}edge[MAXM];
void add_edge(int from,int to)
{
    edge[++tot].to=to;edge[tot].next=head[from];head[from]=tot;
}

void init()
{
    tot = 0;
    for (int i = 1; i <= n; i ++) head[i] = 0, d[i] = 0, leaf[i] = 0;
}

void solve()
{
    n = read(), k = read();
    init();
    for (int i = 1; i < n; i ++)
    {
        int u, v;
        u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
        d[u] ++, d[v] ++;
    }
    if (k == 1)
    {
        printf("%d\n", n - 1);
        return;
    }
    for (int i = 1; i <= n; i ++)
    {
        if (d[i] == 1)
        {
            int to = edge[head[i]].to;
            leaf[to] ++;
            d[i] = 0;
        }
    }
    int ans = 0;
    queue <int> q;
    for (int i = 1; i <= n; i ++)
        if (leaf[i] >= k)
            q.push(i);
    while (q.size())
    {
        int now = q.front();
        q.pop();
        int tmp = leaf[now] / k;
        ans += tmp;
        d[now] -= k * tmp;
        leaf[now] -= k * tmp;
        if (d[now] == 1)
        {
            d[now] = 0;
            for (int i = head[now]; i; i = edge[i].next)
            {
                int to = edge[i].to;
                if (d[to] > 1)
                {
                    leaf[to] ++;
                    if (leaf[to] >= k)
                        q.push(to);
                }
            }
        }
    }
    printf("%d\n", ans);
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