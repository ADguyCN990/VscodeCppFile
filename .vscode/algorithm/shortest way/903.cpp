#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;
#define ll long long
#define MAXN 105
#define INF 0x3f3f3f3f
ll rk[MAXN];
ll dis[MAXN];
int vis[MAXN];
ll price[MAXN][MAXN];
ll x[MAXN];
ll n,m;
ll ans=INF;

ll dij()
{
    int pos=0;
    ll mn;
    for(int i=1;i<=n;i++)
        dis[i]=price[0][i];
    for(int i=1;i<=n;i++)
    {
        pos=0;
        mn=INF;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&dis[j]<mn)
            {
                mn=dis[j];
                pos=j;
            }
        }

        if(pos==0) break;
        vis[pos]=1;

        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&price[pos][j]>0&&price[pos][j]+dis[pos]<dis[j])
            {
                dis[j]=price[pos][j]+mn;
            }
        }

    }
    
    return dis[1];
}

void solve()
{
    cin>>m>>n;//m为限制等级的条件
    for(int i=1;i<=n;i++)
    {
        cin>>price[0][i]>>rk[i]>>x[i];
        for(int j=1;j<=x[i];j++)
        {
            int num,p;
            cin>>num>>p;
            price[num][i]=p;
        }
    }

    for(int i=1;i<=n;i++)
    {
        int now=rk[i];
        for(int j=1;j<=n;j++)
        {
            if(rk[j]>now||now-rk[j]>m)
            {
                vis[j]=1;
            }
            else
                vis[j]=0;
        }
        ans=min(ans,dij());
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}