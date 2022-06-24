#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define mod  1000000007
ll ans[MAXN];
int t,n;
void pre()
{
    ans[0]=1;ans[1]=1;ans[2]=1;
    for(int i=3;i<=200000;i++)
    {
        ans[i]=ans[i-1]*i%mod;
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    pre();
    while(t--)
    {
        cin>>n;
        cout<<ans[n*2]<<endl;
    }

    return 0;
}