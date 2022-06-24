#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 500005
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
ll n,m;
int son[500005][15],tot,cnt[MAXN],sum[MAXN];
int s[MAXN];

void insert(int s[],int len)
{
    int now=0;
    for(int i=1;i<=len;i++)
    {
        int u=s[i];
        if(!son[now][u])
            son[now][u]=++tot;
        now=son[now][u];
        sum[now]++;//经过now
    }
    cnt[now]++;//以now结束
}

ll query(int s[],int len)
{
    int now=0;
    ll ans=0;
    for(int i=1;i<=len;i++)
    {
        int u=s[i];
        if(cnt[now])
            ans+=cnt[now];
        if(!son[now][u])
            return ans;
        now=son[now][u];
    }
    ans=ans+sum[now];
    return ans;
}

void solve()
{
    n=read(),m=read();
    rep(i,1,n)
    {
        int len=read();
        rep(i,1,len) s[i]=read();
        insert(s,len);
    }
    rep(i,1,m)
    {
        int len=read();
        rep(i,1,len) s[i]=read();
        printf("%lld\n",query(s,len));
    }
}

int main()
{
    solve();
    return 0;
}