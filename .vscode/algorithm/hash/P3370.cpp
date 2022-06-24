#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 23333
#define base 261
string s;
ll n;
vector <string> mp[mod+5];
int ans=0;

ll hashing(string s)
{
    ll hash=1;
    for(int i=0;i<s.length();i++)
    {
        hash=(hash*base*1ll+s[i])%mod;
    }
    return hash;
}

void insert(string s,ll hash)
{
    for(auto now:mp[hash])
    {
        if(now==s) return;
    }
    mp[hash].emplace_back(s);ans++;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        ll hash=hashing(s);
        insert(s,hash);
        
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}