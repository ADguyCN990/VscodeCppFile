#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
ll n,m;
int f[MAXN];
struct node
{
    ll u,v,val;
}edge[MAXM];
bool cmp(node a,node b) {return a.val<b.val;}
int findx(int x)
{
    if(x==f[x]) return f[x];
    else return f[x]=findx(f[x]);
}
void merge(int x,int y)
{
    int fx=findx(x);
    int fy=findx(y);
    if(fx!=fy) f[fy]=fx;
}
ll ans=0;
int cnt=0;
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++)
    {
        cin>>edge[i].u>>edge[i].v>>edge[i].val;
    }
    sort(edge+1,edge+1+m,cmp);
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        ll u,v,val;
        u=edge[i].u;v=edge[i].v;val=edge[i].val;
        if(findx(u)!=findx(v))
        {
            merge(u,v);
            ans=val;
            cnt++;
        }
        if(cnt==n-1) break;
    }
    cout<<n-1<<" "<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}