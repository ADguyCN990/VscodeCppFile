#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 2005
#define MAXM 200005
ll ans,n,m;
int f[MAXN];
struct node
{
    ll u,v,val;
}edge[MAXM];
bool cmp(node a,node b){return a.val<b.val;}

int findx(int x)
{
    if(x==f[x]) return x;
    return f[x]=findx(f[x]);
}

void merge(int x,int y)
{
    int fx=findx(x);
    int fy=findx(y);
    if(fy!=fx) f[fy]=fx;
}
int cnt=0;
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++)
    {
        int p,u,v,w;
        cin>>p>>u>>v>>w;
        if(p==1)
        {
            ans+=w;
            merge(u,v);
        }
        else
        {
            edge[++cnt].u=u;edge[cnt].v=v;edge[cnt].val=w;
        }
    }
    sort(edge+1,edge+1+cnt,cmp);
    for(int i=1;i<=cnt;i++)
    {
        int x=edge[i].u;int y=edge[i].v;int val=edge[i].val;
        if(findx(x)!=findx(y))
        {
            merge(x,y);
            ans+=val;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}