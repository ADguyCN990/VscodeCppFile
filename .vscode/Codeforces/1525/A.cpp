#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll k;
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
    cin>>k;
    ll a=k;ll b=100-k;
    ll real_a=a/gcd(a,b);ll real_b=b/gcd(a,b);
    cout<<real_a+real_b<<endl;
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