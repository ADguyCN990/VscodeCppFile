#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 2005
#define MAXM MAXN*MAXN
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
    int to,next,val;
}edge[MAXM];
void add_edge(int from,int to,int val)
{
    edge[++tot].to=to;edge[tot].val=val;edge[tot].next=head[from];head[from]=tot;
}

int n, m;   //n个火车站，m条线路
int vis[MAXN];
int cnt,indgr[MAXN];    //得到的拓扑序，在这上面求最长路
int dis[MAXN];

void topu()
{
    queue<int> q;
    for (int i = 1; i <= n + m; i++)
    {
        if (!indgr[i])
            q.push(i);
    }
    while (q.size())
    {
        int now = q.front(); q.pop();
        for (int i = head[now]; i; i = edge[i].next)
        {
            int to = edge[i].to;
            int val = edge[i].val;
            if (dis[to] < dis[now] + val)
            {
                dis[to] = dis[now] + val;
            }
            if (--indgr[to] == 0)
                q.push(to);
        }
    }
}

void solve()
{
    n = read(); m = read();
    for (int cnt = 1; cnt <= m; cnt++)
    {
        int k;
        k = read();
        memset (vis, 0, sizeof vis);
        int start = INF;  //起点站，值是最小的
        int end = -1;    //终点站，值是最大的
        for (int i = 1; i <= k; i++)
        {   
            int tmp;
            tmp = read();
            start = min (start, tmp);
            end = max (end, tmp);
            vis[tmp] = 1;   //表示该站点需要停靠
        }
        //虚拟节点连边，
        int fake = n + cnt;
        for (int i = start; i <= end; i++)
        {
            if (vis[i]) //该站点需要停靠
                add_edge(fake, i, 1), indgr[i]++;
            else
                add_edge(i, fake, 0), indgr[fake]++;
        }   
    }
    for (int i = 1; i <= n; i++) dis[i] = 1;
    topu();
    
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max (ans, dis[i]);
    printf("%d\n", ans);
}

int main()
{
    solve();
    return 0;
}