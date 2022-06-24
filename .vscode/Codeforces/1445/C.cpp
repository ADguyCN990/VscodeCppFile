#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
ll p,q,x;
void solve()
{
    cin>>p>>q;
    ll ans=0;
    ll Q=q;
    for(int i=2;i*i<=q;i++)
    {
        if(q%i==0)
        {
            while(q%i==0)
                q/=i;
            ll x=p;
            while(x%Q==0)
                x/=i;
            ans=max(ans,x);
        }
    }
    if(q>1)
    {
        ll x=p;
        while(x%Q==0)
            x/=q;
        ans=max(ans,x);
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