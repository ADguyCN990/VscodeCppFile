#include<bits/stdc++.h>
using namespace std;
#define MAXN 2000005
#define ll long long
#define mod 998244353
ll n;
ll dp[MAXN];//可以证明，当我们先考虑最边上i个点，可以贡献1*dp[n-i]的答案
ll dive[MAXN];//某个数的因子数量,处理所有区间长度都相等情况

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=1000000;i++)
    {
        for(int j=i;j<=1000000;j+=i)
        {
            dive[j]++;
        }
    }
    dp[1]=1;
    dp[2]=3;
    ll sum=4;
    for(int i=3;i<=n;i++)
    {
        dp[i]=(sum+dive[i])%mod;
        sum=(sum+dp[i])%mod;
    }
    cout<<dp[n]<<endl;
    return 0;
}