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
int n, m;
int dis[MAXN];
bool vis[MAXN];
int head[MAXN];int tot;
struct EDGE
{
    int to,next,val;
}edge[MAXM];
void add_edge(int from,int to,int val)
{
    edge[++tot].to=to;edge[tot].val=val;edge[tot].next=head[from];head[from]=tot;
}

void spfa(int s)
{
    queue <int> q;
    q.push(s);
    for (int i = 2; i <= n; i ++) dis[i] = INF;
    vis[s] = true;
    while (q.size())
    {
        int now = q.front();
        q.pop();
        vis[now] = false;
        for (int i = head[now]; i; i = edge[i].next)
        {
            int to = edge[i].to;
            int val = edge[i].val;
            if (dis[to] > dis[now] + val)
            {
                dis[to] = dis[now] + val;
                if (vis[to] == false)
                {
                    vis[to] = true;
                    q.push(to);
                }
            }
        }

    }
}

void solve()
{
    n = read(), m = read();    
    for (int i = 1; i <= m; i ++)
    {
        int u, v, w;
        u = read(), v = read(), w = read();
        add_edge(u, v, w);
    }
    spfa(1);
    for (int i = 2; i <= n; i ++)
    {
        printf("%d\n", dis[i]);
    }
}

int main()
{
    solve();
    return 0;
}