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
int head[MAXN];int tot;
struct EDGE
{
    int to,next;
}edge[MAXM];
void add_edge(int from,int to)
{
    edge[++tot].to=to;edge[tot].next=head[from];head[from]=tot;
}
int n, m;
int a[MAXN];
int mood[MAXN];
int happy[MAXN], sad[MAXN], siz[MAXN];
void init()
{
    for (int i = 1; i <= n; i ++) head[i] = 0;
    tot = 0;
}
bool flag = true;
void dfs(int now, int pre)
{
    siz[now] = a[now];
    int sum_happy = 0;
    for (int i = head[now]; i; i = edge[i].next)
    {
        int to = edge[i].to;
        if (to == pre) continue;
        dfs(to, now);
        siz[now] += siz[to];
        sum_happy += happy[to];
    }
    happy[now] = (siz[now] + mood[now]) / 2;
    sad[now] = siz[now] - happy[now];
    if (siz[now] + mood[now] < 0 || sad[now] < 0 || (siz[now] + mood[now]) & 1 || sum_happy > happy[now])
        flag = false;
}


void solve()
{
    n = read(), m = read();
    init();
    for (int i = 1; i <= n; i ++) a[i] = read();
    for (int i = 1; i <= n; i ++) mood[i] = read();
    for (int i = 1; i < n; i ++)
    {
        int u, v;
        u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    flag = true;
    dfs(1, -1);   
    if (flag)
        puts("YES");
    else
        puts("NO");
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