#include<bits/stdc++.h>
using namespace std;
#define ll long long


void solve()
{
    ll n;
    cin>>n;
    ll ans=0;
    string s=to_string(n);
    string temp;
    for(int i=0;i<s.length();i++)
    {
        temp+=s[0];
    }
    if(s>=temp) ans+=(s[0]-'0');
    else if(s<temp) ans+=s[0]-'0'-1;
    if(n<=9)
    {
        cout<<n<<endl;
        return;
    }
    while(n>=10)
    {
        ans+=9;
        n/=10;
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