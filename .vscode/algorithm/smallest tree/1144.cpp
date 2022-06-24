#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
#define MAXM MAXN*MAXN
ll n,m,ans;
int f[MAXM];

int get(int x,int y)
{
    return (x-1)*m+y;
}

int findx(int x)
{
    if(x==f[x]) return x;
    else return f[x]=findx(f[x]);
}

void merge(int x,int y)
{
    int fx=findx(x);
    int fy=findx(y);
    if(fx!=fy) f[fy]=fx;
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) f[i]=i;
    int x,y,u,v;
    while(cin>>x>>y>>u>>v)
    {
        int xx=get(x,y);
        int yy=get(u,v);
        merge(xx,yy);
    }
    //纵向连接
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<n;j++)
        {
            int x=get(j,i);
            int y=get(j+1,i);
            if(findx(x)!=findx(y))
            {
                merge(x,y);
                ans++;
            }
        }
    }
    //横向连接
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<m;j++)
        {
            int x=get(i,j);
            int y=get(i,j+1);
            if(findx(x)!=findx(y))
            {
                merge(x,y);
                ans+=2;
            }
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