#include<iostream>
using namespace std;
#define ll long long
#define MAXN 50005
ll n,m;
ll f[MAXN];ll val[MAXN];
ll temp;
ll ans;
int findx(int x)
{
    if(x!=f[x])
    {
        int t=f[x];
        f[x]=findx(f[x]);
        val[x]=(val[x]+val[t])%3;
    }
    return f[x];
}

void merge(int x,int y)
{
    int fx=findx(x);
    int fy=findx(y);
    if(fx==fy)
    {
        if(temp!=(val[y]-val[x]+3)%3)
            ans++;
    }
    else
    {
        f[fy]=fx;
        val[fy]=(val[x]+temp-val[y])%3;
    }
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++)
    {
        ll u,v;
        cin>>temp>>u>>v;
        if(u>n||v>n||(temp==2&&u==v))
        {
            ans++;
            continue;
        }
        if(temp==1) temp=0;//相同
        else if(temp==2) temp=1;//A吃B
        merge(u,v);
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}