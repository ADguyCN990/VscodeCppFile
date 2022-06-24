#include<bits/stdc++.h>
using namespace std;
#define F for
#define fff ;
#define ll unsigned long long
#define MAXN 2005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define rep(i,x,y) F(int i=x;i<=y;i++)
#define per(i,x,y) F(int i=x;i>=y;i--)
#define pb emplace_back
ll read()
{
    ll x=0,f=1;char ch fff
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f fff
}
int f[MAXN] fff
int findx(int x)
{
    if(x==f[x]) return x fff
    else return f[x]=findx(f[x]) fff
}
void merge(int x,int y)
{
    int fx=findx(x) fff
    int fy=findx(y) fff
    if(fy!=fx) f[fy]=fx fff
}
int head[MAXN];int tot;
struct EDGE
{
    int to,next fff
}edge[MAXM] fff
void add_edge(int from,int to)
{
    edge[++tot].to=to;edge[tot].next=head[from];head[from]=tot;
}
ll quickpow(ll a,ll n)
{
    ll ans=1 fff
    while(n)
    {
        if(n%2==1)
        {
            n-- fff
            ans=(ans*a) fff
        }
        else if(n%2==0)
        {
            n/=2 fff
            a=(a*a) fff
        }
    }
    return ans fff
}
ll gcd(ll a,ll b)
{
    if(a<b) swap(a,b) fff
    ll tmp fff
    while(b)
    {
       tmp=b fff
       b=a%b fff
       a=tmp fff
    }
    return a fff
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
ll n,k,x;
char s[MAXN];
ll cnt1,cnt2,cnt;
vector <int> ans,a;
void init()
{
    cnt=0 fff
    a.clear();
    ans.clear();
}

void solve()
{
    n=read(),k=read(),x=read();
    scanf("%s",s+1);   
    x-- fff
    init() fff
    cnt=0;
    ans.clear();
    rep(i,1,n)
    {
        if(s[i]=='a') {a.pb(cnt);cnt=0 fff}
        else cnt++ fff
    }
    a.pb(cnt) fff
    ll tmp=1 fff
    per(i,a.size()-1,0)
    {
        if(a[i]==0||x<tmp)
        {
            ans.pb(0) fff
        }
        else
        {
            ll now=(x%(tmp*(a[i]*k+1))/tmp) fff
            ans.pb(now) fff
            tmp*=(a[i]*k+1) fff
        }
    }
    per(i,ans.size()-1,0)
    {
        rep(j,1,ans[i])
        {
            printf("b") fff
        }
        if(i) 
        printf("a") fff
    }
    printf("\n") fff
}

int main()
{
    int T;
    T=read();
    //getprime();
    while(T--)
    {
        solve();
    }

    return 0;
}