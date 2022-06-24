#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 400005*32
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
ll son[MAXN][2],tot,tmp;
ll pre[400005],suf[400005];
ll n,a[400005];
void insert(ll x)
{
    int now=0;
    for(int i=31;i>=0;i--)
    {
        int u=(x>>i)&1;
        if(!son[now][u])
            son[now][u]=++tot;
        now=son[now][u];
    }
}

ll query(ll x)
{
    int now=0;
    ll ans=0;
    for(int i=31;i>=0;i--)
    {
        int u=(x>>i)&1;
        if(son[now][!u])
        {
            ans=ans*2+!u;
            now=now[son][!u];
        }
        else
        {
            ans=ans*2+u;
            now=now[son][u];
        }
    }
    return ans;
}

void init()
{
    memset(son,0,sizeof son);
    tot=0;tmp=0;
    insert(0);
}

void solve()
{
    n=read();
    rep(i,1,n) a[i]=read();
    tmp=0;
    rep(i,1,n)
    {
        tmp^=a[i];
        insert(tmp);
        //printf("tmp: %lld\n",tmp);
        pre[i]=max(pre[i-1],query(tmp)^tmp);
    }
    init();
    for(int i=n;i>=1;i--)
    {
        tmp^=a[i];
        insert(tmp);
        //printf("tmp: %lld\n",tmp);
        suf[i]=max(suf[i+1],query(tmp)^tmp);
    }
    ll ans=0;
    //rep(i,1,n) printf("%lld %lld\n",pre[i],suf[i]);
    rep(i,1,n-1)
        ans=max(ans,pre[i]+suf[i+1]);
    printf("%lld\n",ans);
}

int main()
{
    solve();
    return 0;
} 