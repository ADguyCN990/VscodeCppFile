#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
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

ll mp[MAXN][30];
ll cnt[MAXN],tot;
char s[MAXN];int len;
char c[10];
void insert(char s[],int len)
{
    int now=0;//为根节点
    for(int i=1;i<=len;i++)
    {
        int u=s[i]-'a';
        if(!mp[now][u]) mp[now][u]=++tot;
        now=mp[now][u];
    }
    cnt[now]++;
}

int query(char s[],int len)
{
    int now=0;
    for(int i=1;i<=len;i++)
    {
        int u=s[i]-'a';
        if(!mp[now][u]) return 0;
        now=mp[now][u];
    }
    return cnt[now];
}

void solve()
{
    int n;
    n=read();
    while(n--)
    {
        scanf("%s",c);
        scanf("%s",s+1);
        int len=strlen(s+1);
        if(c[0]=='I') insert(s,len);
        else printf("%d\n",query(s,len));
    }
}

int main()
{
    solve();
    return 0;
}