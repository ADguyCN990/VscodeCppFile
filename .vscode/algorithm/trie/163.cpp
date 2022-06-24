#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
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
ll n;
ll son[MAXN][15],tot,cnt[MAXN];
char s[MAXN][15];

void insert(char s[])
{
    int len=strlen(s+1);
    int now=0;
    for(int i=1;i<=len;i++)
    {
        int u=s[i]-'0';
        if(!son[now][u]) 
            son[now][u]=++tot;
        now=son[now][u];
    }
    cnt[now]++;
}

bool query(char s[])
{
    int len=strlen(s+1);
    int now=0;
    for(int i=1;i<=len;i++)
    {   
        int u=s[i]-'0';
        if(cnt[now]) return false;
        now=son[now][u];
    }
    if(cnt[now]>1) return false;
    return true;
}

void solve()
{
    memset(son,0,sizeof son),tot=0,memset(cnt,0,sizeof cnt);
    n=read();
    rep(i,1,n) scanf("%s",s[i]+1),insert(s[i]);
    rep(i,1,n)
    {
        bool flag=query(s[i]);
        if(!flag)
        {
            puts("NO");
            return;
        }
    }
    puts("YES");
}

int main()
{
    int T;
    T=read();
    while(T--)
    {
        solve();
    }

    return 0;
}