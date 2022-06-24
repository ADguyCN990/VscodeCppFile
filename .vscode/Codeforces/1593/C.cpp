#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 400005
ll a[MAXN];
bool cmp(ll a,ll b){return a>b;}
void solve()
{
    ll n,k;
    cin>>n>>k;
    for(int i=1;i<=k;i++) cin>>a[i];
    sort(a+1,a+1+k,cmp);
    int ans=0;
    int cnt=0;
    for(int i=1;i<=k;i++)
    {       
        if(cnt>n) break;
        else if(cnt<=n&&cnt<a[i]) ans++;
        cnt+=(n-a[i]);
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