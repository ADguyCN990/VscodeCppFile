#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 5005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define pb emplace_back
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
ll son[MAXN][2],tot;
ll cnt[MAXN];
ll n,k,sum;
char s[MAXN];
int T;

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

void init()
{
    memset(cnt,0,sizeof cnt);
    memset(son,0,sizeof son);
    tot=0;sum=quickpow(2,n);
}

void insert(char s[])
{
    int len=strlen(s+1);
    int now=0;
    for(int i=1;i<=len;i++)
    {
        int u=s[i]-'B';
        if(u) u=1;
        if(!son[now][u])
            son[now][u]=++tot;
        now=son[now][u];
    }
    cnt[now]++;
}

void dfs(int now,int depth)
{
    if(cnt[now])
    {
        sum-=quickpow(2,n-depth);
        return;
    }
    if(son[now][0]) dfs(son[now][0],depth+1);
    if(son[now][1]) dfs(son[now][1],depth+1);
}

void solve(int id)
{
    n=read(),k=read();
    init();
   // printf("sum: %lld\n",sum);
    for(int i=1;i<=k;i++)
    {
        scanf("%s",s+1);
        insert(s);
    }
    dfs(0,0);
    printf("Case #%d: %lld\n",id,sum);
}

int main()
{
    T=read();
    rep(i,1,T)
    {
        solve(i);
    }

    return 0;
}