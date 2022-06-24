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
ll s;
int leaf[MAXN]; //每个点的连接的叶子节点数量
ll a[MAXN]; //记录边的权值
struct node
{
    int id;
    ll val;
    // [边权 - 边权 / 2] * 该边连接的叶子节点数量
    bool operator< (const node& a) const{
        return (val + 1) / 2 * leaf[id] < (a.val + 1) / 2 * leaf[a.id];
    }
};
priority_queue <node> q;
int head[MAXN];int tot;
struct EDGE
{
    int to,next;
    ll val;
}edge[MAXM];
void add_edge(int from,int to,ll val)
{
    edge[++tot].to=to;edge[tot].val=val;edge[tot].next=head[from];head[from]=tot;
}
void init()
{
    tot = 0;
    for (int i = 1; i <= n; i ++) head[i] = 0, leaf[i] = 0, a[i] = 0;
    while (q.size()) q.pop();
}

void dfs(int now, int pre)
{
    bool isleaf = true; // 标记是否为叶子节点
    for (int i = head[now]; i; i = edge[i].next)
    {
        int to = edge[i].to;
        ll val = edge[i].val;
        if (to == pre) continue;
        isleaf = false;
        a[to] = val;
        dfs(to, now);
        leaf[now] += leaf[to];
    }
    if (isleaf) leaf[now] = 1;
    return;
}

void solve()
{
    n = read(), s = read();
    init();
    for (int i = 1; i < n; i ++)
    {
        int u, v;
        ll w;
        u = read(), v = read(), w = read();
        add_edge(u, v, w), add_edge(v, u, w);
    }
    ll sum = 0;
    dfs(1, -1);
    for (int i = 1; i <= n; i ++)
    {
        //printf("leaf: %d val: %d\n", leaf[i], a[i]);
        sum += leaf[i] * a[i];
    }
    if (sum <= s)
    {
        puts("0");
        return;
    }
    for (int i = 2; i <= n; i ++)
    {
        
        node tmp = {i, a[i]};
        q.push(tmp);
    }
    int ans = 0;
    while (sum > s)
    {
        ans ++;
        int now = q.top().id;
        ll val = q.top().val;
        q.pop();
        sum -= (val + 1) / 2 * leaf[now];
        q.push({now, val / 2});
    }
    printf("%d\n", ans);
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