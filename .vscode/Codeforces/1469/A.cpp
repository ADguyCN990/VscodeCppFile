#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;

void solve()
{
    cin>>s;
    int n=s.length();
    if(n%2==1)
    {
        cout<<"NO"<<endl;
        return;
    }
    if(s[0]==')'||s[n-1]=='(')
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
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