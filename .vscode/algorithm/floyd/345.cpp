#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 210
#define INF 0x3f3f3f3f
ll g[MAXN][MAXN];
ll res[MAXN][MAXN];
int k,n,m,S,E;
map <int,int> mp;//离散化用

void mul(ll c[][MAXN],ll a[][MAXN],ll b[][MAXN])
{
    static ll tmp[MAXN][MAXN];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            tmp[i][j]=INF;
   
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                tmp[i][j]=min(tmp[i][j],a[i][k]+b[k][j]);
    memcpy(c,tmp,sizeof(tmp));
}

void qmi()//倍增
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            res[i][j]=INF;
    for(int i=1;i<=n;i++)
        res[i][i]=0;
    while(k)
    {
        if(k%2==1)
            mul(res,res,g);//res=res*g
        mul(g,g,g);//g=g*g
        k/=2;
    }
}

void solve()
{
    cin>>k>>m>>S>>E;
    if(mp[S]==0) mp[S]=++n;
    if(mp[E]==0) mp[E]=++n;
    S=mp[S];E=mp[E];
    for(int i=1;i<=MAXN;i++)
        for(int j=1;j<=MAXN;j++)
            g[i][j]=INF;
    
    for(int i=1;i<=m;i++)
    {
        ll u,v,w;
        cin>>w>>u>>v;
        if(mp[u]==0) mp[u]=++n;
        if(mp[v]==0) mp[v]=++n;
        u=mp[u],v=mp[v];
        g[u][v]=g[v][u]=min(g[u][v],w); 
    }
    qmi();
    cout<<res[S][E];
}

int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}