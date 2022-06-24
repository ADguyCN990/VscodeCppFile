#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
ll a[MAXN];
ll b[MAXN];
ll n,m;
bool cmp(ll a,ll b) {return a>b;}
void solve()
{
    ll ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    sort(a+1,a+1+n,cmp);
    int pos=1;
    for(int i=1;i<=min(n,m);i++)
    {
        //冤大头先去抢东西
        if(a[i]<i) break;
        pos++;
        ans+=b[i];
    }
    for(int i=pos;i<=n;i++)
        ans+=b[a[i]];
    cout<<ans<<endl;
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

