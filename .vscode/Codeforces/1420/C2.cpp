#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

ll n,q;
ll a[MAXN];
ll ans;
void init()
{
    ans=0,a[0]=0,a[n+1]=0;
}

void solve()
{
    n=read(),q=read();
    rep(i,1,n) a[i]=read();
    init();
    rep(i,1,n)
    {
        ans+=max(a[i]-a[i-1],0ll);
    }
    cout<<ans<<endl;
    while(q--)
    {
        ll l,r;
        l=read(),r=read();
        ans-=max(0ll,a[l]-a[l-1]);
        if(r!=l+1) 
        ans-=max(0ll,a[r]-a[r-1]);
        ans-=max(0ll,a[l+1]-a[l]);
        ans-=max(0ll,a[r+1]-a[r]);
        swap(a[l],a[r]);
        ans+=max(0ll,a[l]-a[l-1]);
        if(r!=l+1) 
        ans+=max(0ll,a[r]-a[r-1]);
        ans+=max(0ll,a[l+1]-a[l]);
        ans+=max(0ll,a[r+1]-a[r]);
        cout<<ans<<endl;
    }
}


int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    T=read();
    while(T--)
    {
        solve();
    }

    return 0;
}