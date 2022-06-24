#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
vector <int> mp[MAXN];
#define ll long long
double ans=0;
int cnt=0;int head[MAXN];
int indgr[MAXN];
ll n,m;
struct edge
{
    int to,next,from;
    double val;
}edge[MAXN];
void add_cnt(int from,int to,double val)
{
    edge[++cnt].to=to;edge[cnt].val=val;edge[cnt].next=head[from];head[from]=cnt;
}

void topp()
{
    queue <int> q;
    q.push(1);
    while(!q.empty())
    {
        int now=q.front();q.pop();
        cout<<"now: "<<now<<endl;
        double son=mp[now].size();
        cout<<now<<"outdgr: "<<son<<endl;
        for(int i=head[now];i;i=edge[i].next)
        {
            ans=ans+(1.0)/(son+0.0)*edge[i].val+0.0;
            indgr[edge[i].to]--;
            if(indgr[edge[i].to]==0) q.push(edge[i].to);
        }
    }
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int from,to;
        double val;
        cin>>from>>to>>val;
        add_cnt(from,to,val);
        indgr[to]++;
        mp[from].emplace_back(to);
    }
    topp();
   
    cout<<ans<<endl;
}

int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}