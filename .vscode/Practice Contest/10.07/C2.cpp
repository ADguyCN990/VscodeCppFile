#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<int, int> pr;
const int MAXN = 1e5 + 5;
const int N = MAXN * 40;
const int inf = 1e9 + 114514;
const LL linf = 1e18 + 114514;
const int M = 314;
#define mid ((l + r) >> 1)
int cnt, mn[N], ls[N], rs[N], root[MAXN];
void insert(int pre, int &rt, int l, int r, int pos, int val)
{
    // printf("%d %d\n",l,r);
    if (!rt)
        rt = ++cnt, mn[rt] = pre ? mn[pre] : inf;
    if (l == r)
        return void(mn[rt] = min(mn[rt], val));
    if (pos <= mid)
        insert(ls[pre], ls[rt], l, mid, pos, val), rs[rt] = rs[pre];
    else
        insert(rs[pre], rs[rt], mid + 1, r, pos, val), ls[rt] = ls[pre];
    if (ls[rt])
        mn[rt] = min(mn[rt], mn[ls[rt]]);
    if (rs[rt])
        mn[rt] = min(mn[rt], mn[rs[rt]]);
}
int query(int rt, int l, int r, int nl, int nr)
{
    if (!rt || nl > nr || nr < l || nl > r)
        return inf;
    if (l == nl && r == nr)
        return mn[rt];
    if (nr <= mid)
        return query(ls[rt], l, mid, nl, nr);
    if (nl > mid)
        return query(rs[rt], mid + 1, r, nl, nr);
    return min(
        query(ls[rt], l, mid, nl, mid),
        query(rs[rt], mid + 1, r, mid + 1, nr));
}
int n, m;
vector<pr> seg[MAXN];
vector<int> v[MAXN];
LL f[MAXN];
bool g[MAXN];
LL solve(vector<int> &a)
{
    //sort(a.begin(),a.end());
    int len = a.size();
    for (int i = 1; i <= len; ++i)
    {
        f[i] = linf;
        for (int j = 1; j <= i; j++)
        {
            LL w = query(root[a[j - 1]], 0, n, a[i - 1], n);
            if (w == inf)
                w = linf;
            // printf("w=%lld %d %d\n",w,a[j-1],a[i-1]);
            f[i] = min(f[i], f[j - 1] + w);
        }
        // printf("f:%d=%lld\n",i,f[i]);
    }
    return f[len] >= linf ? -1 : f[len];
}
namespace nnk
{
    const int N = 1e5 + 5;
    int n, m;
    int l0[N], r0[N], w[N], tot = 0;
    int q[N] = {0};
    struct node
    {
        int v;
        LL w;
    };
    bool operator<(const node &a, const node &b)
    {
        return a.w > b.w;
    }
    vector<node> e[N];
    LL dis[N];
    int vis[N];
    void dijkstra(int n)
    {
        priority_queue<node> q;
        for (int i = 0; i <= n; i++)
        {
            dis[i] = linf;
            vis[i] = 0;
        }

        dis[0] = 0;
        q.push({0, 0});
        while (!q.empty())
        {
            node t = q.top();
            q.pop();
            int u = t.v;
            if (vis[u])
                continue;
            vis[u] = 1;
            for (int i = 0; i < e[u].size(); i++)
            {
                int v = e[u][i].v;
                int w = e[u][i].w;
                if ((!vis[v]) && (dis[v] > dis[u] + w))
                {
                    dis[v] = dis[u] + w;
                    q.push({v, dis[v]});
                }
            }
        }
    }
    void read_seg(int i, int l, int r, int _w)
    {
        tot++, l0[i] = l, r0[i] = r, w[i] = _w;
    }
    LL solve(vector<int> &a)
    {
        int qsiz = a.size();
        for (int i = 0; i <= qsiz; ++i)
        {
            e[i].clear();
        }
        for (int i = 1; i <= qsiz; ++i)
        {
            // scanf("%d", &q[i]);
            q[i] = a[i - 1];
            e[i].push_back({i - 1, 0});
        }
        //sort(q + 1, q + qsiz + 1);

        for (int i = 1; i <= tot; ++i)
        {
            int l = lower_bound(q, q + qsiz + 1, l0[i]) - q;
            int r = upper_bound(q, q + qsiz + 1, r0[i]) - q - 1;
            e[max(0, l - 1)].push_back({r, w[i]});
            //cout << max(0, l - 1) << ' ' << r << endl;
        }
        dijkstra(qsiz);
        //for (int i = 0;i <= qsiz;++i) cout << i << ':' << dis[i] <<
        //endl;
        return (dis[qsiz] == linf) ? -1 : dis[qsiz];
    }
}
int main()
{
    scanf("%d%d", &n, &m), nnk::n = n, nnk::m = m;
    for (int i = 1; i <= m; i++)
    {
        int t, l, r, w, k;
        scanf("%d", &t);

        if (t == 1)
            scanf("%d%d%d", &l, &r, &w), seg[l].push_back({r, w}), nnk::read_seg(i, l, r, w);
        if (t == 2)
        {
            scanf("%d", &k);
            while (k--)
                scanf("%d", &w), v[i].push_back(w);
            g[i] = 1;
        }
    }
    int pre = 0, cur = 0;
    for (int i = 0; i <= n; i++)
    {
        for (auto p : seg[i])
        {
            cur = 0;
            insert(pre, cur, 0, n, p.first, p.second);
            pre = cur;
        }
        root[i] = pre;
    }
    for (int i = 1; i <= m; i++)
        if (g[i])
            printf("%lld\n", v[i].size() <= M ? solve(v[i]) : nnk::solve(v[i]));
    return 0;
}