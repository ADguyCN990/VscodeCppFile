#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 10000
int prime[MAXN+5];
void pre()
{
    memset(prime,0,sizeof(prime));
    for(int i=2;i<=MAXN;i++)
    {
        if(!prime[i]) prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<=MAXN/i;j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}

void solve()
{
    ll n;
    cin>>n;
    for(int i=n*4,cnt=1;cnt<=n;i-=2,cnt++)
        cout<<i<<" ";
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    pre();
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}