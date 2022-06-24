#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
ll n,k;
ll a[MAXN];
bool cmp(ll a,ll b){return a>b;}
void solve()
{
    ll n,k;
    cin>>k>>n;
    //一共n组，每组k个
    for(int i=1;i<=n*k;i++) 
        cin>>a[i];
    ll ans=0;
    int pos=k/2+1;
    ll cnt=0;
    for(int i=n*k-pos+1;;i-=pos)
    {
        cnt++;
        if(cnt>n) break;
        ans+=a[i];
    }
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