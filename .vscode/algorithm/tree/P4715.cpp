#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 305
ll a[MAXN];
ll win[MAXN];
ll n;
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

void dfs(int rt)
{
    if(rt>=quickpow(2,n)) return;//遍历到了叶子节点
    dfs(2*rt);dfs(2*rt+1);
    if(a[2*rt]>a[2*rt+1])
    {
        win[rt]=win[2*rt];
        a[rt]=a[2*rt];
    }
    else if(a[2*rt]<a[2*rt+1])
    {
        win[rt]=win[2*rt+1];
        a[rt]=a[2*rt+1];
    }
}

void solve()
{
    cin>>n;
    for(int i=0;i<quickpow(2,n);i++)
    {
        cin>>a[quickpow(2,n)+i];
        win[quickpow(2,n)+i]=i+1;
    }
    dfs(1);
    if(a[2]>a[3])
    {
        cout<<win[3]<<endl;
    }
    else
    {
        cout<<win[2]<<endl;
    }
   // for(int i=1;i<=quickpow(2,n+1);i++) cout<<win[i]<<" ";
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();

    return 0;
}