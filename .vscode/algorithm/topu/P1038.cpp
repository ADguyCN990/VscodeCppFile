#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
#define MAXM MAXN*MAXN
ll n,m;
ll u[MAXN];//每个节点一开始的阈值
ll c[MAXN];//ci=sum(边权*cj)-ui
int indgr[MAXN];
int outdgr[MAXN];
struct node
{
    int to,next,val;
}edge[MAXM];
int head[MAXM];int cnt;
void add_edge(int from,int to,int val)
{
    edge[++cnt].to=to;edge[cnt].val=val;edge[cnt].next=head[from];head[from]=cnt;
}

void topp()
{
    queue <int> q;
    for(int i=1;i<=n;i++) 
    {
        if(c[i]>0&&indgr[i]==0) q.push(i);
    }
    while(!q.empty())
    {
        int now=q.front();q.pop();
        for(int i=head[now];i;i=edge[i].next)
        {
            int j=edge[i].to;
            indgr[j]--;
            c[j]=c[j]+edge[i].val*c[now];
            if(indgr[j]==0) 
            {
                c[j]-=u[j];
                if(c[j]>0) q.push(j);
            }
        }
    }
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i]>>u[i];
    }
    //ci大于0并且入度数为0就入队
    for(int i=1;i<=m;i++)
    {
        int u,v,val;
        cin>>u>>v>>val;
        add_edge(u,v,val);
        indgr[v]++;
        outdgr[u]++;
    }
    topp();
    vector <pair<int,int>> ans;
    int f=0;
    for(int i=1;i<=n;i++)
    {
        if(outdgr[i]==0&&c[i]>0) 
        {
            f=1;
            ans.emplace_back(make_pair(i,c[i]));
        }
    }
    if(f==0) cout<<"NULL"<<endl;
    else for(auto x:ans) cout<<x.first<<" "<<x.second<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}