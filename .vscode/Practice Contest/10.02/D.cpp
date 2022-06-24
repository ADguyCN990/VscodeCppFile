#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll t;
ll l1,r1,l2,r2;
#define N 10000000
ll prime[N+5];
void getprime()
{
    for(ll i=2;i<=N;i++)
    {
        if(!prime[i]) prime[++prime[0]]=i;
        for(ll j=1;j<=prime[0]&&prime[j]<=N/i;j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}

void solve()
{
    cin>>l1>>r1>>l2>>r2;
    for(ll i=1;i<=prime[0];i++)
    {
        if(prime[i]>max(r1,r2)) break;
        ll sum1=0;ll sum2=0;
        for(ll j=prime[i];j<=max(r1,r2);j*=prime[i])
        {
            sum1+=r1/j-(l1-1)/j;
            sum2+=r2/j-(l2-1)/j;
        }
        if(sum1>sum2)
        {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    getprime();
    while(t--)
    {
        solve();
    }
    

    return 0;
}