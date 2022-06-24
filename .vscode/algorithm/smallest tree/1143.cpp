#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define MAXM 100005
int f[MAXN];
ll n,k;
struct node
{
    ll u,v,val;
}e[MAXM];

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
ll tot=0;//原先的花费
ll ans=0;//后来的花费

bool cmp(node a,node b) {return a.val<b.val;}

void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=k;i++)
    {
        ll u,v,val;
        cin>>e[i].u>>e[i].v>>e[i].val;
        tot+=e[i].val;
    }
    sort(e+1,e+1+k,cmp);
    for(int i=1;i<=k;i++)
    {
        ll u=e[i].u;ll v=e[i].v;ll val=e[i].val;
        if(findx(u)!=findx(v))
        {
            merge(u,v);
            ans+=val;
        }
    }
    cout<<tot-ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}