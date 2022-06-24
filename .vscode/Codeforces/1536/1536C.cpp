#include<bits/stdc++.h>
using namespace std;
#define MAXN 500005
#define ll long long
string s;
ll t,n;

map <pair<ll,ll>,int> mp;
ll gcd(ll a,ll b)
{
    ll temp;
    if(a<b) swap(a,b);
    while(b)
    {
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>s;
        mp.clear();
        ll a=0;ll b=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='D') a++;
            else if(s[i]=='K') b++;
            ll x=gcd(a,b);
            mp[make_pair(a/x,b/x)]++;
            cout<<mp[make_pair(a/x,b/x)]<<" ";
        }
        cout<<endl;
    }
    return 0;
}