#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
#define MAXN 100005
#define lson tree[rt << 1]
#define rson tree[rt << 1 | 1]
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

ll lowbit(ll x) {return x & -x;}
int n, m;
ll a[MAXN];

struct node {
    int l, r;
    ll sum;
    bool flag; 
    ll mul;
}tree[MAXN << 4];

void pushup(int rt) {
    tree[rt].sum = (lson.sum + rson.sum) % mod;
    tree[rt].flag = lson.flag & rson.flag;
}

void pushdown(int rt) {
    if (tree[rt].mul != 1) {
        lson.sum = lson.sum * tree[rt].mul % mod;
        rson.sum = rson.sum * tree[rt].mul % mod;
        lson.mul = lson.mul * tree[rt].mul % mod;
        rson.mul = rson.mul * tree[rt].mul % mod;
        tree[rt].mul = 1;   
    }
}

void build(int rt, int l, int r) {
    tree[rt].l = l, tree[rt].r = r, tree[rt].flag = false, tree[rt].sum = 0, tree[rt].mul = 1;
    if (l == r) {
        tree[rt].sum = a[l];
        if (a[l] == lowbit(a[l])) {
            tree[rt].flag = true;
        }
        return;
    }
    int mid = tree[rt].l + tree[rt].r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}

void update(int rt, int l, int r) {
    if (tree[rt].l >= l && tree[rt].r <= r && tree[rt].flag) {
        tree[rt].sum = tree[rt].sum * 2 % mod;
        tree[rt].mul = tree[rt].mul * 2 % mod;
        return;
    }
    if (tree[rt].l == tree[rt].r) {
        tree[rt].sum += lowbit(tree[rt].sum);
        if (tree[rt].sum == lowbit(tree[rt].sum)) tree[rt].flag = true;
        return;
    }
    int mid = tree[rt].l + tree[rt].r >> 1;
    pushdown(rt);
    if (l <= mid) update(rt << 1, l, r);
    if (mid + 1 <= r) update(rt << 1 | 1, l, r);
    pushup(rt);
}

ll query(int rt, int l, int r) {
    if (tree[rt].l >= l && tree[rt].r <= r) {
        return tree[rt].sum;
    }
    int mid = tree[rt].l + tree[rt].r >> 1;
    pushdown(rt);
    ll ans = 0;
    if (l <= mid) ans = (ans + query(rt << 1, l, r)) % mod;
    if (mid + 1 <= r) ans = (ans + query(rt << 1 | 1, l, r)) % mod;
    return ans;
}

void solve() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    build(1, 1, n);
    m = read();
    while (m--) {
        int opt = read(), l = read(), r = read();
        if (opt == 1) {
            update(1, l, r);
        }
        else {
            printf("%lld\n", query(1, l ,r));
        }
    }
}

int main() {
    int t = read();
    while (t--)
        solve();
    return 0;
}