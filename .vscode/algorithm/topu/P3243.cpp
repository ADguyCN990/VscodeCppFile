#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define ll long long
ll n,m;
int head[MAXN];int cnt=0;
int indgr[MAXN];
vector <int> ans;
struct node
{
    int to,next;
}edge[MAXN];
void add_edge(int from,int to)
{
    edge[++cnt].to=to;edge[cnt].next=head[from];head[from]=cnt;
}
void init()
{
    cnt=0;
    ans.clear();
    for(int i=1;i<=n;i++) 
    {
        indgr[i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        head[i]=0;
        edge[i].to=0;edge[i].next=0;
    }
}
void build()
{
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        add_edge(v,u);
        indgr[u]++;
    }
}
void topp()
{
    priority_queue <int> q;
    for(int i=n;i>=1;i--)
    {
        if(indgr[i]==0) 
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int now=q.top();q.pop();
        ans.emplace_back(now);
        for(int i=head[now];i;i=edge[i].next)
        {
            int j=edge[i].to;
            indgr[j]--;
            if(indgr[j]==0)
            {
                //ans.emplace_back(j);
                q.push(j);
            }
        }
    }
}
void output()
{
    if(ans.size()!=n) cout<<"Impossible!";
    else 
    {
       for(int i=ans.size()-1;i>=0;i--) cout<<ans[i]<<" ";
    }
    cout<<endl;
}
void solve()
{
    cin>>n>>m;
    init();
    build();
    topp();
    output();
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