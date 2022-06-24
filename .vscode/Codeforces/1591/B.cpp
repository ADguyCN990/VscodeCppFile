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
#define per(i,x,y) for(int i=x;i>=y;i--)
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
ll n;
ll a[MAXN];
ll ans,cur,mx;
void init()
{
    cur=a[n];
    mx=0;
    ans=0;
}
void solve()
{
    n=read();
    rep(i,1,n) a[i]=read();
    init();
    per(i,n,1)
    {
        if(cur==mx) 
            break;
        else if(a[i]>cur)
        {
            ans++;
            cur=a[i];
        }
    }
    cout<<ans<<endl;
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