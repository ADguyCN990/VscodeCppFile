#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define debug(x) cout<<"!!!"<<x<<endl
#define pb emplace_back
#define xx first
#define yy second
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
int head[MAXN];int tot;
struct EDGE
{
    int to,next,val;
}edge[MAXM];
void add_edge(int from,int to,int val)
{
    edge[++tot].to=to;edge[tot].val=val;edge[tot].next=head[from];head[from]=tot;
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
    int fx = findx(x);
    int fy = findx(y);
    if (fy != fx)
        f[fy] = fx;
}
ll n,m;
string s,t;
map<string,int> mp;
void init()
{
    s="";
    t="";
    mp.clear();
}

string get(ll x)
{
    string ans="";
    while(x)
    {
        int tmp=x&1;
        ans=(char)('0'+tmp)+ans;
        x=x>>1;
    }
    return ans;
}

string work1(string s)
{
    string ans="";
    s+='1';
    int len=s.length();
    per(i,len-1,0) ans+=s[i];
    return ans;
}

string work2(string s)
{
    string ans="";
    s+='0';
    int len=s.length();
    int f1=0;
    per(i,len-1,0)
    {
        if(s[i]=='1') f1=1;
        if(!f1) continue;
        ans+=s[i];
    }
    if(ans=="") ans="0";//防止空串（也就是0）的情况出现
    return ans;
}

bool dfs(string s)
{
    if(s==t)
        return true;//可行性剪枝
    if((int)(s.length())>(int)(t.length()))
        return false;//可行性剪枝
    if(mp.count(s))
        return false;//冗余性剪枝
    mp[s]++;
    string ss=work1(s);
    string sss=work2(s);
    bool flag1=dfs(ss);
    bool flag2=dfs(sss);
    return flag1|flag2;
}

void solve()
{
    n=read(),m=read();
    if(n==m)
    {
        cout<<"YES"<<endl;
        return;
    }
    s=get(n),t=get(m);
    // cout<<s<<endl;
    // cout<<t<<endl;
    bool flag= dfs(work1(s))|dfs(work2(s)) ;
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    // int T;
    // T=read();
    // while(T--)
    // {
    //     solve();
    // }
    solve();
    return 0;
}