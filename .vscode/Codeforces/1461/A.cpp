#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
ll n,k;

void solve()
{
    cin>>n>>k;
    string s="abc";
    for(int i=0;i<n;i++)
    {
        cout<<s[i%3];
    }
    cout<<endl;
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