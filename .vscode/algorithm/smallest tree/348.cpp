#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 6005
#define MAXM MAXN*MAXN
int cnt;
ll n,ans;
int f[MAXN];
ll siz[MAXN];//每个连通块的个数
struct node
{
    ll u,v,w;
}edge[MAXM];
bool cmp(node a,node b) {return a.w<b.w;}

int findx(int x)
{
    if(x==f[x]) return x;
    else return f[x]=findx(f[x]);
}

void merge(int x,int y,ll w)
{
    int fx=findx(x);
    int fy=findx(y);
    if(fx!=fy)
    {
        ans+=(siz[fx]*siz[fy]-1)*(w+1);
        f[fy]=fx;
        siz[fx]+=siz[fy];
    }
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        f[i]=i;
        siz[i]=1;
    }
    ans=0;cnt=n-1;
    for(int i=1;i<=cnt;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        edge[i].u=u;edge[i].v=v;edge[i].w=w;
    }
    sort(edge+1,edge+1+cnt,cmp);
    for(int i=1;i<=cnt;i++)
    {
        int u=edge[i].u;int v=edge[i].v;ll val=edge[i].w;
        if(findx(u)!=findx(v))
            merge(u,v,val);
    }
    cout<<ans<<endl;
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