#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
//找出[1,n-1]的最长子序列，使得子序列所有值的乘积模n=1
vector <ll> ans;
ll gcd(ll a,ll b)
{
    if(a<b) swap(a,b);
    ll temp;
    while(b)
    {
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
void solve()
{
    cin>>n;
    ll sum=1;
    for(int i=1;i<n;i++) 
    {
        if(gcd(n,i)==1) 
        {
            ans.emplace_back(i);
            sum=(sum*i)%n;
        }
    }
   
    if(sum==1)
    {
        cout<<ans.size()<<endl;
        for(auto x:ans) cout<<x<<" ";
    }
    else
    {
        cout<<ans.size()-1<<endl;
        for(auto x:ans)
        {
            if(x==sum) continue;
            cout<<x<<" ";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}