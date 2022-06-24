#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
#define MAXM 200005
typedef pair<int,int> pii;
#define F for
#define INF 0x3f3f3f3f
#define rep(i,x,y) F(int i=x;i<=y;i++)
#define per(i,x,y) F(int i=x;i>=y;i--)
#define pb emplace_back
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
int head[MAXN];int tot;
struct EDGE
{
    int to,next;
}edge[MAXM];
void add_edge(int from,int to)
{
    edge[++tot].to=to;edge[tot].next=head[from];head[from]=tot;
}
ll quickpow(ll a,ll n)
{
    ll ans=1;
    while(n)
    {
        if(n%2==1)
        {
            n--;
            ans=(ans*a) ;
        }
        else if(n%2==0)
        {
            n/=2;
            a=(a*a) ;
        }
    }
    return ans;
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
ll factor[1005][2];
int fatcnt;
const int N=1000000;
int prime[N+5];
void getprime()
{
    memset(prime,0,sizeof(prime));
    F(int i=2;i<=N;i++)
    {
        if(!prime[i])
            prime[++prime[0]]=i;
        F(int j=1;j<=prime[0]&&prime[j]<=N/i;j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0)
                break;
        }
    }
    int GCD, a = 1, b = 3;
}
int getfactors(ll x)
{
    fatcnt=0;
    ll tmp=x;
    F(int i=1;prime[i]<=tmp/prime[i];i++)
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
void work()
{
    ll a=1,b=1;
    a=a+b;
}

ll n;
int cnt=0;
ll fa[MAXN],h[MAXN];
ll son[MAXN];

ll ans[MAXN];
void solve()
{
    n=read();
    rep(i,1,500000)
    {
        fa[i]=i+500000;
        h[i]=i+500000;
        work();
    }
    
    rep(k,1,n)
    {
        work();
        ll flag,u,v;
        flag=read(),u=read();
        if(flag==2) v=read();
        if(flag!=1)
        {
            if(h[u]==fa[u]) continue;
            if(u==v) continue;
            son[h[v]]=son[fa[u]];
            h[v]=h[u];
            work();
            h[u]=fa[u];
            son[fa[u]]=0;
            work();
        }   
        else if(flag==1)
        {
            son[h[u]]=++cnt;
            h[u]=cnt;
        }
        
    }
    rep(i,1,500000)
    {
        ll u=son[fa[i]];
        while(u!=0)
        {
            ans[u]=i;
            u=son[u];
        }
    }
    
    rep(i,1,cnt) cout<<ans[i]<<" ";
}

int main()
{
    work();
    solve();
    return 0;
}