#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define pb emplace_back
#define mod 1000000007
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int f[MAXN];
int findx(int x)
{
    if(x==f[x]) return x;
    else return f[x]=findx(f[x]);
}

void merge(int x,int y)
{
    int fx=findx(x);
    int fy=findx(y);
    if(fy!=fx) f[fy]=fx;
}

const int N=1000000;
int prime[N+5];
void getprime()
{
    memset(prime,0,sizeof(prime));
    for(int i=2;i<=N;i++)
    {
        if(!prime[i])
            prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<=N/i;j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0)
                break;
        }
    }
}
ll factor[1005][2];
int fatcnt;
int getfactors(ll x)
{
    fatcnt=0;
    ll tmp=x;
    for(int i=1;prime[i]<=tmp/prime[i];i++)
    {
        factor[fatcnt][1]=0;
        if(tmp%prime[i]==0)
        {
            factor[fatcnt][0]=prime[i];
            while(tmp%prime[i]==0)
            {
                factor[fatcnt][1]++;
                tmp/=prime[i];
            }
            fatcnt++;
        }
    }
    if(tmp!=1)
    {
        factor[fatcnt][0]=tmp;
        factor[fatcnt++][1]=1;
    }
    return fatcnt;
}
int head[MAXN];int tot;
struct EDGE
{
    int to,next,val;
}edge[MAXM];
void add_edge(int from,int to,int val)
{
    edge[++tot].to=to;edge[tot].val=val;edge[tot].next=head[from];head[from]=tot;
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

ll gcd(ll a,ll b)
{
    if(a<b) swap(a,b);
    ll tmp;
    while(b)
    {
       tmp=b;
       b=a%b;
       a=tmp; 
    }
    return a;
}

void work()
{
    int a=1,b=2;
    a=a+b;
}

ll n,x;
ll a[MAXN];
int vis[MAXN];
ll ans;
void init()
{
    rep(i,1,n) vis[i]=0;
    vis[1]=1;
    ans=0;
}


void solve()
{
    n=read();
    init();
    rep(i,1,n) a[i]=read();
    work();
    x=read();
    work();
    rep(i,2,n)
    {
        if(vis[i-1]!=0)
        {
            if(a[i-1]+a[i]<2*x) continue;
            if(vis[i-2]&&a[i-2]+a[i]+a[i-1]>=3*x&&a[i-1]+a[i]>=2*x)
            {               
                vis[i]=1;
                ans++;     
                work();           
            }
            else if(!vis[i-2]&&a[i-1]+a[i]>=2*x&&a[i-1]+a[i]>=2*x)
            {
                vis[i]=1;
                ans++;
            }
            work();
        }
        else if(!vis[i-1])
        {
            work();
            ans++;
            vis[i]=1;
            
        }
    }
    printf("%d\n",ans+1);
    work();
}

int main()
{
    getprime();
    int T;
    T=read();
    while(T--)
    {
        solve();
    }

    return 0;
}