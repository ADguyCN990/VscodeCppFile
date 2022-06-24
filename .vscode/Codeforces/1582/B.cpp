#include<bits/stdc++.h>
using namespace std;
#define MAXN 70
#define ll long long
ll n;
ll a[MAXN];
int cnt=0;//1
int num=0;//0

ll quickpow(ll a,ll n)
{
    ll ans=1;
    while(n)
    {
        if(n%2==1)
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
    cin>>n;
    ll ans=0;
    cnt=0;
    ll sum=0;
    num=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        if(a[i]==1) cnt++;
        if(a[i]==0) num++;
    }
    // if(sum==1) 
    // {
    //     if(n==1)
    //     {
    //         cout<<1<<endl;
    //         return;
    //     }
    //     cout<<1+cnt<<endl;
    //     return;
    // }
    
    ans=quickpow(2,num)*cnt;   
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