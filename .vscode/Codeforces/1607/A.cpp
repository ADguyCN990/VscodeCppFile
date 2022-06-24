#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s,t;
map <char,int> mp;

void solve()
{
    cin>>t>>s;
    mp.clear();
    for(int i=0;i<t.length();i++)
    {
        mp[t[i]]=i+1;
    }
    ll ans=0;
    for(int i=0;i<s.length()-1;i++)
    {
        ans+=abs(mp[s[i+1]]-mp[s[i]]);
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