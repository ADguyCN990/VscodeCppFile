#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 305
#define MAXM 200005
ll n,ans;
int f[MAXN];
int cnt;

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

struct node
{
    int u,v,val;
}edge[MAXM];
bool cmp(node a,node b) {return a.val<b.val;}
void solve()
{
    cin>>n;
    for(int i=0;i<=n;i++) f[i]=i;
    for(int i=1;i<=n;i++)
    {
        ll w;
        cin>>w;
        edge[++cnt].u=0;edge[cnt].v=i;edge[cnt].val=w;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ll w;
            cin>>w; 
            edge[++cnt].u=i;edge[cnt].v=j;edge[cnt].val=w;
        }
    }
    
    sort(edge+1,edge+1+cnt,cmp);
    
    for(int i=1;i<=cnt;i++)
    {
        ll u,v,w;
        u=edge[i].u;v=edge[i].v;w=edge[i].val;
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