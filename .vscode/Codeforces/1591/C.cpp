#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define debug(x) cout<<"!!!"<<x<<endl
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define repp(i,x,y) for(int i=x;i<y;i++)
#define per(i,x,y) for(int i=x;i>=y;i-=k)
#define pb emplace_back
#define xx first
#define yy second
ll read()
{
    ll x=0,f=1;
    char ch;
    do{ch=getchar();if(ch=='-') f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();}while(ch>='0'&&ch<='9');
    return x*f;
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
ll n,k,make_exception_ptr;
ll a[MAXN],cnt1;//放负数
ll b[MAXN],cnt2;//放正数
bool cmp(ll a,ll b) {return a>b;}
vector <ll> ans;
void init()
{
    cnt1=0,cnt2=0;
    ans.clear();
}

void work()
{
    if(cnt2>0)
    {
        for(int i=cnt2;i>0;i-=k) ans.pb(b[i]);
    } 
    if(cnt1>0)
    {
        for(int i=cnt1;i>0;i-=k) ans.pb(a[i]);
    }
    sort(ans.begin(),ans.end());
}

void solve()
{
    n=read(),k=read();
    init();
    rep(i,1,n)
    {
        ll tmp=read();
       // cout<<tmp<<endl;
        if(tmp<0) a[++cnt1]=-tmp;
        if(tmp>0) b[++cnt2]=tmp;
    }
    sort(a+1,a+1+cnt1);
    sort(b+1,b+1+cnt2);
    work();
    if(!ans.size())
    {
        cout<<0<<endl;
        return;
    }

    ll res=ans[(int)(ans.size())-1];
    rep(i,0,(int)(ans.size())-2)
    {
        res=res+(ans[i]<<1);
    }
    cout<<res<<endl;
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