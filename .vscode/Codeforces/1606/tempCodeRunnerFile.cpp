#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    string s;
    cin>>s;
    int cnt1=0;int cnt2=0;
    n=s.length();
    for(int i=0;i<s.length()-1;i++)
    {
        if(s[i]=='a'&&s[i+1]=='b') cnt1++;
        if(s[i]=='b'&&s[i+1]=='a') cnt2++;
    }
    if(cnt1==cnt2)
    {
        cout<<s<<endl;
        return;
    }
    if(cnt1>cnt2)//AB>BA
    {
        if(s[0]=='a'&&s[1]=='b') s[0]='a';
        else if(s[1]=='a'&&s[0]=='a') s[0]='b';
        else if(s[n-2]=='a'&&s[n-1]=='b') s[n-1]='a';
    }
    else
    {
        if(s[0]=='b'&&s[1]=='a') s[0]='a';
        else if(s[1]=='b'&&s[0]=='b') s[0]='a';
        else if(s[n-2]=='b'&&s[n-1]=='a') s[n-1]='b';
    }
    cout<<s<<endl;
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