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
ll resa[MAXN * 30], resb[MAXN * 30], idx1, idx2;
ll sum1[MAXN * 30], sum2[MAXN * 30];
struct node
{
    int x, y;
    ll val;
    int opt;
}c[MAXN];

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
    idx1 = 0, idx2 = 0;

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
}
bool isdata, getdata;
void solve()
{
    n = read(), s = read();
    init();
    for (int i = 1; i < n; i ++)
    {
        int u, v;
        ll w;
        int opt;
        u = read(), v = read(), w = read(), opt = read();
        add_edge(u, v, w), add_edge(v, u, w);
        c[i] = {u, v, w, opt};
    }
    // if (isdata && ! getdata) return;
    // if (isdata && getdata)
    // {
    //     printf("%d %lld\n", n, s);
    //     for (int i = 1; i < n; i ++)
    //     {
    //         printf("%d %d %lld %d\n", c[i].x, c[i].y, c[i].val, c[i].opt);
    //     }
    //     return;
    // }
    dfs(1, -1);
    ll sum = 0;
    for (int i = 1; i < n; i ++)
    {
        int u = c[i].x, v = c[i].y;
        ll val = c[i].val;
        if (leaf[u] < leaf[v]) swap(u, v);
        // 保证u一定是父亲，v一定是儿子
        //printf("fa: %d son: %d leaf: %d val: %d\n", u, v, leaf[v], val);
        sum += leaf[v] * val;
        if (c[i].opt == 1)
        {
            while (val)
            {
                ll remove = (val + 1) / 2 * leaf[v];
                resa[++ idx1] = remove;
                val /= 2;
            }
        }
        else
        {
            while (val)
            {
                ll remove = (val + 1) / 2 * leaf[v];
                resb[++ idx2] = remove;
                val /= 2;
            }
        }
    }
    if (sum <= s)
    {
        puts("0");
        return;
    }
    //printf("%lld\n", sum);
    sort(resa + 1, resa + 1 + idx1, greater<ll>());
    sort(resb + 1, resb + 1 + idx2, greater<ll>());
    for (int i = 1; i <= idx1; i ++) sum1[i] = sum1[i - 1] + resa[i];
    for (int i = 1; i <= idx2; i ++) sum2[i] = sum2[i - 1] + resb[i];
    ll ans = 0x3f3f3f3f3f3f3f3f;
    for (int i = 0; i <= idx1; i ++)
    {
        ll tmp = -1;
        int l = 0, r = idx2;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (sum - (sum1[i] + sum2[mid]) <= s) //当前方案可行
            {
                tmp = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        if (tmp != -1) ans = min(ans, i + tmp * 2);
    }
    printf("%lld\n", ans);
}

int main()
{
    int T;
    T=read();
    if (T == 200)
        isdata = true;
    else
        isdata = false;
    for (int i = 1; i <= T; i ++)
    {
        if (i == 4) 
            getdata = true;
        else
            getdata = false;
        solve();
    }

    return 0;
}