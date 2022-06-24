#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 500005
#define MAXM 200005
typedef pair<int,int> pii;
#define debug(x) cout<<"!!!"<<x<<endl
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define repp(i,x,y) for(int i=x;i<y;i++)
#define pb emplace_back
#define xx first
#define yy second
ll read()
{
    ll x=0,f=1;
    char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'&&ch>'9');
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
ll n;
ll a[MAXN];
int cnt[MAXN];
int st[MAXN];
bool flag;
int mx=0;
vector <ll> b;
void init()
{
    rep(i,1,n) cnt[i]=0,st[i]=0;
    flag=false;
}

bool judge()
{
    sort(b.begin()+1,b.end());
    int num=0;
    rep(i,1,n)
    {
        if(a[i]!=b[i])
            num++;
    }
    if(!num)
    {
        cout<<"YES"<<endl;
        return true;
    }
    if(n<=2)
    {
        cout<<"NO"<<endl;
        return true;
    }
    if(flag)
    {
        cout<<"YES"<<endl;
        return true;
    }
    
   
    return false;
}

int dfs(int now,int step)
{
    mx++;
    st[now]=1;
    if(!st[cnt[a[now]]])
        dfs(cnt[a[now]],step+1);
    return mx;
}

void solve()
{
    n=read();
    init();
    b.clear();
    b.pb(0);
    rep(i,1,n)
    {
        a[i]=read();
        b.pb(a[i]);
        cnt[a[i]]++;
        if(cnt[a[i]]>1)
            flag=true;
    }
    bool f=judge();
    if(f) return;
    ll ans=0;
    rep(i,1,n)
    {
        cnt[b[i]]=i;
    }
    rep(i,1,n)
    {
        if(a[i]==b[i]) continue;
        if(st[i]) continue;
        int tmp=0;       
        mx=0,tmp=dfs(i,0);
        if(tmp>0&&!(tmp&1)) 
            ans++;
    }
    if(!(ans&1))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
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