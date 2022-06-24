#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 30005
ll n,m;

void solve()
{
    cin>>n>>m;
    ll tmp=n*m;
    int cnt=0;
    if(n*m%3==0)
    {
        cout<<n*m/3<<endl;
        return;
    }
    while(tmp%3!=0)
    {
        tmp-=2;
        cnt++;
    }
    cout<<cnt+tmp/3<<endl;
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