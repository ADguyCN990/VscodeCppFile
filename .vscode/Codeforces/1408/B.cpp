#include<bits/stdc++.h>
using namespace std;
#define MAXN 105
#define ll long long
ll n,k;
ll a[MAXN];
int vis[MAXN];
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    memset(vis,0,sizeof vis);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[a[i]])
        {
            vis[a[i]]=1;
            cnt++;
        }
    }
   
    if(k==1&&cnt>k)
    {
        cout<<-1<<endl;
        return;
    }
    if(k>=cnt)
    {
        cout<<1<<endl;
        return;
    }
    if(a[n]==0)
    {
        cout<<0<<endl;
        return;
    }
    if((cnt-k)%(k-1)==0)
    {
        cout<<1+(cnt-k)/(k-1)<<endl;
        return;
    }
    else
    {
        cout<<2+(cnt-k)/(k-1)<<endl;
    }
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