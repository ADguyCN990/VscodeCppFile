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
int n;
int a[MAXN];
char s[MAXN];
struct node
{
    int x,id,f;
}p[MAXN];

bool cmp(node a,node b)
{
    if(a.f==b.f)
    {
        return a.x<b.x;
    }
    return a.f<b.f;
}

void solve()
{
    n=read();
    rep(i,1,n) a[i]=read();
    scanf("%s",s+1);
    rep(i,1,n) p[i].x=a[i],p[i].id=i,p[i].f=s[i]-'0';
    sort(p+1,p+1+n,cmp);
    for(int i=1;i<=n;i++) a[p[i].id]=i;
    rep(i,1,n) printf("%d ",a[i]);
    puts("");
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