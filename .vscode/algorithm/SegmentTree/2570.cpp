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
int n;
int siz[MAXN], son[MAXN], fa[MAXN], depth[MAXN], top[MAXN];
int key[MAXN], val[MAXN], a[MAXN], cnt;
int head[MAXN];int tot;
struct EDGE
{
    int to,next;
}edge[MAXM];
void add_edge(int from,int to)
{
    edge[++tot].to=to;edge[tot].next=head[from];head[from]=tot;
}
struct node
{
    int l, r, len;
    ll add, sum;
}tree[MAXN << 2];

void dfs1(int now,int dep, int pre) //得到以当前节点为根的子树大小，当前节点的父节点，当前节点的深度，当前节点的重儿子
{
    depth[now] = dep, fa[now] = pre, siz[now] = 1;
    for (int i = head[now]; i; i = edge[i].next)
    {
        int to = edge[i].to;
        if (to == pre) continue;
        dfs1(to, dep + 1, now);
        siz[now] += siz[to];
        if (siz[to] > siz[son[now]])
            son[now] = to;
    }
}

void dfs2(int now,int boss) //按照dfs序给每个节点编号为之后的区间处理做准备
{
    key[now] = ++ cnt, a[cnt] = val[now], top[now] = boss;
    if (!son[now]) return;
    dfs2(son[now], boss);
    for (int i = head[now]; i; i = edge[i].next)
    {
        int to = edge[i].to;
        if (to == fa[now] || to == son[now]) continue;
        dfs2(to, to);
    } 
}

void pushup(int rt)
{
    tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum;
}

void work(node &rt, ll add)
{
    rt.sum += rt.len * add;
    rt.add += add;
}

void pushdown(int rt)
{
    work(tree[rt << 1], tree[rt].add);
    work(tree[rt << 1 | 1], tree[rt].add);
    tree[rt].add = 0;
}

void build(int rt, int l, int r)
{
    tree[rt] = {l, r, r - l + 1, 0, a[l]};
    if (l == r) return;
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}

void update(int rt, int l, int r, int add)
{
    if (tree[rt].l >= l && tree[rt].r <= r)
    {
        work(tree[rt], add);
        return;
    }
    pushdown(rt);
    int mid = tree[rt].l + tree[rt].r >> 1;
    if (mid >= l) update(rt << 1, l, r, add);
    if (mid + 1 <= r) update(rt << 1 | 1, l, r, add);
    pushup(rt);
}

ll query(int rt, int l, int r)
{
    if (tree[rt].l >= l && tree[rt].r <= r)
    {
        return tree[rt].sum;
    }
    pushdown(rt);
    int mid = tree[rt].l + tree[rt].r >> 1;
    ll ans = 0;
    if (mid >= l) ans += query(rt << 1, l, r);
    if (mid + 1 <= r) ans += query (rt << 1 | 1, l, r);
    return ans;
}

void update_tree(int rt, int add)
{
    update(1, key[rt], key[rt] + siz[rt] - 1, add);
}

ll query_tree (int rt)
{
    return query(1, key[rt], key[rt] + siz[rt] - 1);
}

void update_path(int u, int v, int add)
{
    while (top[u] != top[v])
    {
        if (depth[top[u]] < depth[top[v]]) swap(u, v);
        update(1, key[top[u]], key[u], add);
        u = fa[top[u]];
    }
    if (depth[u] < depth[v]) swap(u, v);
    update(1, key[v], key[u], add);
}

ll query_path(int u, int v)
{
    ll ans = 0;
    while (top[u] != top[v])
    {
        if (depth[top[u]] < depth[top[v]]) swap(u, v);
        ans += query(1, key[top[u]], key[u]);
        u = fa[top[u]];
    }
    if (depth[u] < depth[v]) swap(u, v);
    ans += query(1, key[v], key[u]);
    return ans;
}

void solve()
{
    n = read();
    for (int i = 1; i <= n; i ++) val[i] = read();
    for (int i = 1; i < n; i ++)
    {
        int u, v;
        u = read(), v = read();
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs1(1, 1, -1);
    dfs2(1, 1);
    build(1, 1, n);
    int k;
    k = read();
    for (int i = 1; i <= k; i ++)
    {
        int opt;
        int u, v, add;
        opt = read(), u = read();
        if (opt == 1) //修改路径节点权值
        {
            v = read(), add = read();
            update_path(u, v, add);
        }
        else if (opt == 2) //修改子树节点权值
        {
            add = read();
            update_tree(u, add);
        }
        else if(opt == 3) //查询路径节点权值和
        {
            v = read();
            printf("%lld\n", query_path(u, v));
        }
        else //查询子树节点权值和
            printf("%lld\n", query_tree(u));
    }
}

int main()
{
    solve();
    return 0;
}