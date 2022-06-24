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
int head[MAXN];int tot;
struct EDGE
{
    int to,next;
}edge[MAXM];
void add_edge(int from,int to)
{
    edge[++tot].to=to;edge[tot].next=head[from];head[from]=tot;
}
int d[MAXN];
int leave[MAXN]; //叶子数

void init()
{
    tot = 0;
    for (int i = 1; i <= n; i ++) head[i] = 0;
    for (int i = 1; i <= n; i ++) d[i] = 0;
    for (int i = 1; i <= n; i ++) leave[i] = 0;
}

void solve()
{
    n = read(), k = read();
    //只有当一个节点的叶子数大于等于k时才能删
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
    for (int i = 1; i <= n; i ++) //先把所有叶子都找出来
    {
        if (d[i] == 1)
        {
            int fa = edge[head[i]].to;
            leave[fa] ++;
        }
    }
    int ans = 0;
    queue <int> q;
    for (int i = 1; i <= n; i ++)
        if (leave[i] >= k)
            q.push(i);
    while (q.size())
    {
        int now = q.front();
        q.pop();
        int tmp = leave[now] / k;
        ans += tmp;
        d[now] -= tmp * k;
        leave[now] -= tmp * k;
        if (leave[now] == 0 && d[now] == 1) //类似于拓扑结构的递推，这个点已经变成了叶子
        {
            d[now] = 0;
            for (int i = head[now]; i; i = edge[i].next)
            {
                int to = edge[i].to;
                if (d[to] > 1)
                {
                    leave[to] ++;
                    if (leave[to] >= k)
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