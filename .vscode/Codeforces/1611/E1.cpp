#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 400005
typedef pair<pair<int,int>,int> pii;
#define INF 0x3f3f3f3f
int n,k,a[MAXN];
int head[MAXN];int tot;
int isleaf[MAXN];
int d[MAXN],vis[MAXN];//0表示未访问，2表示自己可以走，1表示不能走
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
    tot=0;
    memset(head,0,sizeof(head));
    memset(d,0,sizeof(d));
    memset(vis,0,sizeof(vis));
}

void solve()
{
    init();
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        cin>>a[i];
        vis[a[i]]=1;
    }
    vis[1]=2;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        add_edge(u,v),add_edge(v,u);
        d[u]++,d[v]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(d[i]==1&&i!=1)
            isleaf[i]=1;
        else
            isleaf[i]=0;
    }
    priority_queue <pii,vector<pii>,greater<pii>> q;
    //时间，类型（敌人为1自己为2），位置
    q.push({{0,2},1});
    for(int i=1;i<=k;i++)
        q.push({{0,1},a[i]});
    while(!q.empty())
    {
        int tim=q.top().first.first;int type=q.top().first.second;int now=q.top().second;
        q.pop();
        for(int i=head[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            if(!vis[to])
            {
                vis[to]=type;
                q.push({{tim+1,type},to});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(isleaf[i]&&vis[i]==2)
        {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }

    return 0;
}