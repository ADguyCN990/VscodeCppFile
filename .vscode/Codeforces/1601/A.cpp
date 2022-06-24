#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
string a,b;
int id=0;
void solve()
{
    cin>>s;
    char mn='z';
    a="";b="";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]<=mn)
        {
            mn=s[i];
            id=i;
        }
    }
    a=mn;
    for(int i=0;i<s.length();i++)
    {
        if(i==id) continue;
        b+=s[i];
    }
    cout<<a<<" "<<b<<endl;
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