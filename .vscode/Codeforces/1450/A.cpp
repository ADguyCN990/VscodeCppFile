#include<bits/stdc++.h>
using namespace std;
#define MAXN 205
#define ll long long
ll n;
void solve()
{
    cin>>n;
    string s;
    cin>>s;
    sort(s.begin(),s.end());
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