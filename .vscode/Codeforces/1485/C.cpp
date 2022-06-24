#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll ans,a,b;
//a/b=a%b=x
//  b*x+x=a x<b，b为自变量
void solve()
{
    ll ans=0;
    cin>>a>>b;
    for(int i=1;i*i<=a;i++)//a/i=1+b，i是a的因子
    {
        //根据i匹配b，因为a和b是唯一对应的
        ans+=max(0ll,min(a/i-1,b)-i);//(b>i)，要减
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