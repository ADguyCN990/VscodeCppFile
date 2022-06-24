#include<bits/stdc++.h>
using namespace std;
#define MAXN 2005
#define MAXM 200005
struct Edge
{
    int to, next;
    double val;
} edge[MAXM];
typedef pair<double, int> pdi;
int head[MAXM], cnt, n, m, s, t;
double dis[MAXN];
bool vis[MAXN];
void add(int from, int to, int val)
{
    edge[++cnt].to = to;edge[cnt].val = 1 - val * 0.01;edge[cnt].next = head[from];head[from] = cnt;
}
void dij()
{
    priority_queue<pdi> q;
    for (register int i = 1; i <= n; i++)
    { //dis初始化为最大值
        dis[i] = 1e9;
    }
    q.push({100, t});
    dis[t] = 100;
    while (!q.empty())
    {
        int now = q.top().second;q.pop();
        if (vis[now])
            continue;
        vis[now] = true;
        for (int i = head[now]; i; i = edge[i].next)
        {
            int to = edge[i].to;
            double val = edge[i].val;
            if (dis[to] > dis[now] / val)
            { 
                dis[to] = dis[now] / val;
                q.push({-dis[to], to});
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    cin >> s >> t;
    dij();
    printf("%.8lf", dis[s]);
}
