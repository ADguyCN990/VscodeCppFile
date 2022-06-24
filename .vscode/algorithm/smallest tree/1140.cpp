#include<bits/stdc++.h>
using namespace std;
#define MAXN 105
#define MAXM 10005
#define ll long long
int f[MAXN];
int n;
struct node
{
    int u,v,w;
}edge[MAXM];
int cnt;
bool cmp(node a,node b){return a.w<b.w;}

int findx(int x)
{
    if(x==f[x]) return x;
    return f[x]=findx(f[x]);
}

void merge(int x,int y)
{
    int fx=findx(x);
    int fy=findx(y);
    if(fx!=fy) f[fy]=fx;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int w;
            cin>>w;
            if(i>=j) continue;
            edge[++cnt].u=i;edge[cnt].v=j;edge[cnt].w=w;
        }
    }
    sort(edge+1,edge+1+cnt,cmp);
    ll ans=0;
    for(int i=1;i<=cnt;i++)
    {
        int u=edge[i].u;int v=edge[i].v;int w=edge[i].w;
        if(findx(u)!=findx(v))
        {
            merge(u,v);
            ans+=w;
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