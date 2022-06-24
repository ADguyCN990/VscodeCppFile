#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 2000005
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

char s[MAXN];
ll n,m;
ll son[405][30],tot,cnt[405];

void insert(char s[])
{
    int now=0;
    int len=strlen(s+1);
    for(int i=1;i<=len;i++)
    {
        int u=s[i]-'a';
        if(!son[now][u])
            son[now][u]=++tot;
        now=son[now][u];
    }
    cnt[now]++;
}

ll query(char s[])
{
    int len=strlen(s+1);
    ll ans=0,now=0;
    for(int i=1;i<=len;i++)
    {
        int u=s[i]-'a';
        if(cnt[now]) ans=i-1;
        if(!son[now][u]) return ans;
        now=son[now][u];
    }
    return ans;
}

void solve()
{
    n=read(),m=read();
    rep(i,1,n)
    {
        scanf("%s",s+1);
        insert(s);
    }
    rep(i,1,m)
    {
        scanf("%s",s+1);
        printf("%lld\n",query(s));
    }
}

int main()
{
    solve();
    return 0;
}