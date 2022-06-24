#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll n,x;
ll a[MAXN];
ll quickpow(ll a,ll n)
{
    ll ans=1;
    while(n)
    {
        if(n%2)
        {
            n--;
            ans=ans*a;
        }
        else
        {
            n/=2;
            a=a*a;
        }
    }
    return ans;
}
void solve()
{
    cin>>n>>x;
    ll sum=0;
    ll ans=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        sum+=a[i];
    }
    int cnt=0x3f3f3f3f;//被整除的最小次数
    for(int i=1;i<=n;i++)
    {
        int now=a[i];
        int temp=1;
        while(now%x==0)
        {
            temp++;
            now/=x;
        }
        cnt=min(cnt,temp);
        
    }
    ans=sum*cnt;
    for(int i=1;i<=n;i++)
    {
        if(a[i]%quickpow(x,cnt)==0) ans+=a[i];
        else break;
    }
    cout<<ans<<endl;
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