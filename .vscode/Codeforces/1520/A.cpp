#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
map <char,int> mp;
void solve()
{
    ll n;
    cin>>n>>s;
    mp.clear();
    for(int i=0;i<s.length();i++)
    {
        if(mp[s[i]]==0||(mp[s[i]]>0&&s[i]==s[i-1]))
        {
            mp[s[i]]++;
        }
        else 
        {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
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