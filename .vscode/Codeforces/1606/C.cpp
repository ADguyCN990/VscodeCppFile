#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[15];
ll n,k;
ll get(ll m)
{
    ll ans=1;
    for(int i=1;i<=m;i++) ans*=10;
    return ans;
}
void solve()
{
    memset(a,0,sizeof(a));
    cin>>n>>k;
    k++;//算法求的是最大的合法的，我们要求最小的非法，加个1
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=2;i<=n;i++)
    {
        ll num=get(a[i]-a[i-1])-1;
        if(k>=num)
        {
            ans+=num*get(a[i-1]);
            k-=num;
        }
        else 
        {
            ans+=k*get(a[i-1]);
            k=0;
            break;
        }
    }
    ans+=get(a[n])*k;
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