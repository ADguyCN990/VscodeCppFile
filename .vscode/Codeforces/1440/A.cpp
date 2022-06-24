#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
char s[MAXN];

void solve()
{
    ll n,a,b,h;//a为0b为1
    cin>>n>>a>>b>>h;
    cin>>s+1;
    int cnt0=0;int cnt1=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='0') cnt0++;
        else if(s[i]=='1') cnt1++;
    }
    ll ans=0;
    if(h+b<a)
        ans+=(h+b)*cnt0;
    else 
        ans+=a*cnt0;
    if(h+a<b)
        ans+=(h+a)*cnt1;
    else
        ans+=b*cnt1;
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