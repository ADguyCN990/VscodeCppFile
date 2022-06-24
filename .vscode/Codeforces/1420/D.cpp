#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define mod 998244353
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

ll quickpow(ll a,ll n)
{
    ll ans=1;
    while(n)
    {
        if(n%2==1)
        {
            n--;
            ans=(ans*a) % mod;
        }
        else if(n%2==0)
        {
            n/=2;
            a=(a*a) %mod;
        }
    }
    return ans;
}
ll fac[MAXN],inv[MAXN];
void pre()
{
    fac[0]=1;
    for(int i=1;i<=300000;i++) fac[i]=fac[i-1]*i%mod;
    inv[300000]=quickpow(fac[300000],mod-2);
    for(int i=299999;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}

ll cnm(ll n,ll m)
{
    if(m<0||m>n) return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}

struct node
{
    ll id;
    ll val;
}a[MAXN<<1];//差分

bool cmp(node a,node b)
{
    if(a.id==b.id) return a.val<b.val;
    else return a.id<b.id;
}

ll n,k;
void solve()
{
    n=read(),k=read();
    rep(i,1,n)
    {
        ll tmp;
        tmp=read();
        a[2*i-1].id=tmp,a[2*i-1].val=1;
        tmp=read();
        a[2*i].id=tmp+1,a[2*i].val=-1;
    }
    sort(a+1,a+1+n+n,cmp);
    //差分求组合数
    ll now=0,ans=0;
    for(int i=1;i<=n+n;i++)
    {
        if(a[i].val==1)
        {
            ans=(ans+cnm(now,k-1)%mod)%mod;
        }
        now+=a[i].val;
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    pre(); 
   
    solve();
    return 0;
}