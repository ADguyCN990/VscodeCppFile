#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
int n,m;
ll c[MAXN];

ll lowbit(ll x) {return x&-x;}

ll ask(ll x)
{
    ll ans=0;
    for(ll i=x;i;i-=lowbit(i)) ans+=c[i];
    return ans;
}

void add(ll x,ll k)
{
    for(ll i=x;i<=n;i+=lowbit(i)) c[i]+=k;
}

void solve()
{
    cin>>n>>m;
    while(m--)
    {
        char c;
        ll x,k;
        cin>>c>>x>>k;
        if(c=='x') add(x,k);
        else if(c=='y') cout<<ask(k)-ask(x-1)<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}