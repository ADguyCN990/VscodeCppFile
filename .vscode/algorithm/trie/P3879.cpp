#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 5005
#define MAXM 5000005
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
int son[MAXM][26],tot;
bitset <1005> mp[5000005];
char s[MAXN];

void insert(char s[],int num)
{
    int len=strlen(s+1);
    int now=0;
    for(int i=1;i<=len;i++)
    {
        int u=s[i]-'a';
        if(!son[now][u])
            son[now][u]=++tot;
        now=son[now][u];
    }
    mp[now][num]=1;
}

void query(char s[])
{
    int len=strlen(s+1);
    int now=0;
    for(int i=1;i<=len;i++)
    {
        int u=s[i]-'a';
        if(!son[now][u])
        {
            puts("");
            return;
        }
        now=son[now][u];
    }
    for(int i=1;i<=n;i++)
        if(mp[now][i]==1)
            printf("%d ",i);
    puts("");
}

void solve()
{
    n=read();
    rep(i,1,n)
    {
        int k;k=read();
        while(k--)
        {
            scanf("%s",s+1);
            insert(s,i);
        }
    }
    m=read();
    while(m--)
    {
        scanf("%s",s+1);
        query(s);
    }
}

int main()
{
    solve();
    return 0;
}