#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define per(i, x, y) for (int i = x; i >= y; i--)
#define pb emplace_back
ll read()
{
    ll x = 0, f = 1;
    char ch;
    do
    {
        ch = getchar();
        if (ch == '-')
            f = -1;
    } while (ch < '0' || ch > '9');
    do
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    } while (ch >= '0' && ch <= '9');
    return x * f;
}
ll a[MAXN];
ll n, m, mod;
ll opt, l, r, x, y;
struct node
{
    int l, r, len;
    ll sum;
    ll add, mul; //懒惰标记
} tree[MAXN << 2];

void work(node &now, ll c, ll d) //c(ax+b)+d
{
    now.sum = (now.sum * c + now.len * d) % mod;
    now.mul = (now.mul * c) % mod;
    now.add = (now.add * c + d) % mod;
}

void pushup(int rt)
{
    tree[rt].sum = (tree[rt << 1].sum + tree[rt << 1 | 1].sum) % mod;
}

void pushdown(int rt)
{
    work(tree[rt << 1], tree[rt].mul, tree[rt].add);
    work(tree[rt << 1 | 1], tree[rt].mul, tree[rt].add);
    tree[rt].add = 0;
    tree[rt].mul = 1;
}

void build(int rt, int l, int r)
{
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].len = r - l + 1;
    tree[rt].add = 0, tree[rt].mul = 1;
    if (l == r)
    {
        tree[rt].sum = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}

void update(int rt, int l, int r, ll c, ll d) //c表示乘，d表示加
{
    if (tree[rt].l >= l && tree[rt].r <= r)
    {
        work(tree[rt], c, d);
        return;
    }
    pushdown(rt);
    int mid = tree[rt].l + tree[rt].r >> 1;
    if (mid >= l)
        update(rt << 1, l, r, c, d);
    if (mid + 1 <= r)
        update(rt << 1 | 1, l, r, c, d);
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
    if (mid >= l)
        ans = (ans + query(rt << 1, l, r)) % mod;
    if (mid + 1 <= r)
        ans = (ans + query(rt << 1 | 1, l, r)) % mod;
    return ans;
}

void solve()
{
    n = read(), mod = read();
    rep(i, 1, n) a[i] = read();
    build(1,1,n);
    m = read();
    while (m--)
    {
        opt = read();
        if (opt == 1) //multiply
        {
            l = read(), r = read(), x = read();
            update(1, l, r, x, 0);
        }
        else if (opt == 2)
        {
            l = read(), r = read(), x = read();
            update(1, l, r, 1, x);
        }
        else
        {
            l = read(), r = read();
            printf("%lld\n", query(1, l, r));
        }
    }
}

int main()
{
    solve();
    return 0;
}