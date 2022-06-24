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
int head[MAXN];int tot;
struct EDGE
{
    int to,next;
}edge[MAXM];
void add_edge(int from,int to)
{
    edge[++tot].to=to;edge[tot].next=head[from];head[from]=tot;
}
int d[MAXN];
pii p[MAXN];
int ans[MAXN];
int n;
map <pii, int> mp;

void dfs(int now, int pre, int num)
{
    for (int i = head[now]; i; i = edge[i].next)
    {
        int to = edge[i].to;
        if (to == pre) continue;
        int id = mp[{now, to}];
        ans[id] = num;
        if (num == 2)
            dfs(to, now, 3);
        else
            dfs(to, now, 2);
    }
}

void solve()
{
    n = read();
    bool flag = true;
    tot = 0;
    for (int i = 1; i <= n; i ++) head[i] = 0;
    for (int i = 1; i <= n; i ++) d[i] = 0;
    mp.clear();
    for (int i = 1; i < n; i ++)
    {
        int u, v;
        u = read(), v = read();
        d[u] ++, d[v] ++;
        p[i].first = u, p[i].second = v;
        add_edge(u, v), add_edge(v, u);
        mp[{u, v}] = i, mp[{v, u}] = i;
    }
    for (int i = 1; i <= n; i ++)
    {
        if (d[i] > 2) 
        {
            flag = false;
            break;
        }
    }
    if (!flag) 
    {
        puts("-1");
        return;
    }
    int start;
    for (int i = 1; i <= n; i ++)
    {
        if (d[i] == 1)
        {
            start = i;
            break;
        }
    }
    dfs(start, -1, 2);
    for (int i = 1; i < n; i ++) printf("%d ", ans[i]);
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