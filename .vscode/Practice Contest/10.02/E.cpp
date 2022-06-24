#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 1000010
int n;
int x,y;
int a,b;
struct qnode
{
    int v;int c;
    qnode(int _v=0,int _c=0):v(_v),c(_c){}
    bool operator <(const qnode &r) const{
        return c>r.c;
    }
};
struct edge
{
    int v,cost;
    edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};

vector <edge> e[MAXN];
bool vis[MAXN];
int dist[MAXN];

void dij(int n,int start)
{
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++) dist[i]=INF;
    priority_queue <qnode> que;
    while(!que.empty()) que.pop();
    dist[start]=0;
    que.push(qnode(start,0));
    qnode tmp;
    while(!que.empty())
    {
        tmp=que.top();que.pop();
        int u=tmp.v;
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=0;i<e[u].size();i++)
        {
            int v=e[tmp.v][i].v;
            int cost=e[u][i].cost;
            if(!vis[v]&&dist[v]>dist[u]+cost)
            {
                dist[v]=dist[u]+cost;
                que.push(qnode(v,dist[v]));
            }
        }
    }
}

void add_edge(int u,int v,int w)
{
    e[u].push_back(edge{v,w});
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        add_edge(x,y,1);add_edge(y,x,1);

    }
    cin>>a>>b;
    dij(n,a);
    int temp=dist[b];
    if(temp%2==1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}