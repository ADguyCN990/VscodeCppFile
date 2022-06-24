#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define ll long long
int indgr[MAXN<<1];int head[MAXN<<1]; ll tim[MAXN<<1];
struct node
{
    int to,next,val;

}edge[MAXN<<1];
int cnt=0;
void add_edge(int from,int to,int val)
{
    edge[++cnt].val=val;edge[cnt].to=to;edge[cnt].next=head[from];head[from]=cnt;
}
ll n,m,k;

void solve()
{
    cin>>n>>k>>m;
    for(int i=0;i<=n;i++) 
    {
        head[i]=-1;
        tim[i]=-1;
    }
    tim[0]=0;
    for(int i=1;i<=n;i++)
    {
        int temp;
        cin>>temp;
        add_edge(0,i,temp);
        indgr[i]++;
    }
    for(int i=1;i<=m;i++)
    {
        int to,from,val;
        cin>>from>>to>>val;
        add_edge(from,to,val);
        indgr[to]++;
    }
    queue <int> q;
    q.push(0);
    while(!q.empty())
    {
        int now=q.front();q.pop();
        for(int i=head[now];i!=-1;i=edge[i].next)
        {
            int val=edge[i].val;
            int j=edge[i].to;
            tim[j]=max(tim[j],tim[now]+val);
            indgr[j]--;
            if(indgr[j]==0) q.push(j);
        }
    }
    for(int i=1;i<=n;i++) cout<<tim[i]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}