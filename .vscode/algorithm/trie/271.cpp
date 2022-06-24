#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 12005
#define MAXM 12005*32
#define N 12000
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

int n,m;
int son[MAXN][2],rt[MAXN],sum[MAXN],tot,mx[MAXM];

void insert(int id,int last,int now)
{
    mx[now]=id;
    for(int i=31;i>=0;i--)
    {
        int u=(sum[id]>>i)&1;
        if(last)
            son[now][!u]=son[last][u];
        son[now][u]=++tot;
        
        last=son[last][u],now=son[now][u];
        mx[now]=id;
    }
}

ll query(int now,int l,ll x)
{
    ll ans=0;
    for(int i=31;i>=0;i--)
    {
        int u=(x>>i)&1;
        if(mx[son[now][!u]]>=l)
        {
            ans=ans*2+!u;
            now=son[now][!u];
        }
        else
        {
            ans=ans*2+u;
            now=son[now][u];
        }
    }
    return ans^x;
}

void solve()
{
    n=read(),m=read();
    mx[0]=-114514;
    rt[0]=++tot;
    insert(0,0,rt[0]);
    rep(i,1,n)
    {
        ll x;x=read();
        sum[i]=sum[i-1]^x;
        rt[i]=++tot;
        insert(i,rt[i-1],rt[i]);
    }
    int pre=0;
    while(m--)
    {
        int x,y;
        x=read(),y=read();
        x++,y++;
        int l=min((x+pre)%N+1,(y+pre)%N+1);
        int r=max((x+pre)%N+1,(y+pre)%N+1);
        ll ans=0;
        ans=query(rt[r-1],l-1,0);
        printf("%lld\n",ans);
        pre=ans;
    }
}

int main()
{
    solve();
    return 0;
}