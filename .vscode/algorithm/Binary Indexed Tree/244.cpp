#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll a[MAXN],b[MAXN],c1[MAXN],c2[MAXN];
int n,m;
//c1表示 差分数组b[i] c2表示 差分数组i*b[i]
ll lowbit(ll x) {return x&-x;}

void add(ll x,ll k)
{
    for(ll i=x;i<=n;i+=lowbit(i))
    {
        c1[i]+=k;
        c2[i]+=k*x;
    }
}

ll ask(ll x)
{
    ll ans=0;
    for(ll i=x;i;i-=lowbit(i))
    {
        ans+=(x+1)*c1[i]-c2[i];
    }
    return ans;
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) add(i,a[i]-a[i-1]);
    while(m--)
    {
        char c;
        cin>>c;
        if(c=='Q')//查询
        {
            int l,r;
            cin>>l>>r;
            cout<<ask(r)-ask(l-1)<<endl;
        }   
        else //更新
        {
            ll l,r,k;
            cin>>l>>r>>k;
            add(l,k),add(r+1,-k);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}