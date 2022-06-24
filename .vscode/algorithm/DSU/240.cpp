#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 30005
int f[MAXN];
int n,m;
int dis[MAXN];//每个点到根节点的距离
int siz[MAXN];//以该点为根节点的集团元素个数

int findx(int x)
{
    if(x!=f[x])
    {
        int t=f[x];
        f[x]=findx(f[x]);
        dis[x]+=dis[t];
    }
    return f[x];
}

void merge(int x,int y)
{
    int fx=findx(x);
    int fy=findx(y);
    //x接到y的尾部
    f[fx]=fy;
    dis[fx]=siz[fy];
    siz[fy]+=siz[fx];
}

void solve()
{
    scanf("%d",&m);
    for(int i=1;i<=30000;i++) 
    {
        f[i]=i;
        siz[i]=1;
    }
    for(int i=1;i<=m;i++)
    {
        char c[10];
        int u,v;
        scanf("%s%d%d",c,&u,&v);
        if(c[0]=='M')
        {
            merge(u,v);
        }           
        else
        {
            if(findx(u)==findx(v))
            {
                //cout<<dis[u]<<" "<<dis[v]<<endl;
                cout<<max(0,abs(dis[u]-dis[v])-1)<<endl;
            }
            else
                cout<<-1<<endl;
        }
    }
}

int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}