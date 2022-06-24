#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
ll n;
ll a[MAXN];
void solve()
{
    cin>>n;
    set <int> s;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s.insert(a[i]);
    }
    if(s.size()==n)
        cout<<"NO"<<endl;
    else 
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