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
ll n;
ll a[MAXN];
struct node
{
    int l, r;
    ll sum;
    ll mxopt; //传说中的势能函数
}tree[MAXN << 2];

void pushup(int rt)
{
    tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum;
    tree[rt].mxopt = max(tree[rt << 1].mxopt, tree[rt << 1 | 1].mxopt); //更新势能函数
}

void build(int rt, int l, int r)
{
    tree[rt].l = l, tree[rt].r = r;
    if (l == r)
    {
        tree[rt].sum = a[l];
        tree[rt].mxopt = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}

void update(int rt, int l, int r)
{
    if (tree[rt].l == tree[rt].r) //看似是单点更新，但根据更新上限小的特点时间复杂度说得过去
    {
        tree[rt].sum = (ll)(sqrt(tree[rt].sum));
        tree[rt].mxopt = (ll)(sqrt(tree[rt].mxopt));
        return;
    }
    int mid = tree[rt].l + tree[rt].r >> 1;
    if (mid >= l && tree[rt << 1].mxopt > 1) update(rt << 1, l, r);
    if (mid + 1 <= r && tree[rt << 1 | 1].mxopt > 1) update(rt << 1 | 1, l, r);
    pushup(rt);
}

ll query(int rt, int l, int r)
{
    if (tree[rt].l >= l && tree[rt].r <= r) return tree[rt].sum;
    ll ans = 0;
    int mid = tree[rt].l + tree[rt].r >> 1;
    if (mid >= l) ans += query(rt << 1, l, r);
    if (mid + 1 <= r) ans += query(rt << 1 | 1, l, r);
    return ans;
}

void solve()
{
    n = read();
    for (int i = 1; i <= n; i ++) a[i] = read();
    build(1, 1, n);
    int m;
    m = read();
    while (m --)
    {
        int opt, l, r;
        opt = read(), l = read(), r = read();
        if (l > r) swap(l, r);
        if (opt == 0) update(1, l, r);
        else printf("%lld\n", query(1, l, r));
    }
}

int main()
{
    solve();
    return 0;
}