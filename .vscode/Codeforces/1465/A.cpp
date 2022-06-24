#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
ll n;
void solve()
{
    string s;
    cin>>n;
    cin>>s;
    
    int cnt=0;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]==')') cnt++;
        else break;
    }
    if(cnt*2>n) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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