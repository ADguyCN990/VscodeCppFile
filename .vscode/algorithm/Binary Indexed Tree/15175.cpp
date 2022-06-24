#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define per(i, x, y) for(int i = x; i >= y; i--)
#define pb emplace_back
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
ll a[MAXN];
ll n, m;
char opt[5];
struct node {
    int l, r, len;
    ll sum, add;
}tree[MAXN << 2];

void pushup(int rt) {
    tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum;
}

void build(int rt, int l, int r) {
    tree[rt].l = l, tree[rt].r = r, tree[rt].len = r - l + 1;
    if (l == r) {
        tree[rt].sum = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}

void work(node &now, ll add) {
    now.add += add;
    now.sum += add * now.len;
}

void pushdown(int rt) {
    if (tree[rt].add) {
        work(tree[rt << 1], tree[rt].add);
        work(tree[rt << 1 | 1], tree[rt].add);
        tree[rt].add = 0;
    }
}

void update(int rt, int l, int r, ll val) {
    if (tree[rt].l >= l && tree[rt].r <= r) {
        work(tree[rt], val);
        return;
    }
    pushdown(rt);
    int mid = tree[rt].l + tree[rt].r >> 1;
    if (mid >= l) update(rt << 1, l, r, val);
    if (mid + 1 <= r) update(rt << 1 | 1, l, r, val);
    pushup(rt);
}

ll query(int rt, int l, int r) {
    if (tree[rt].l >= l && tree[rt].r <= r) {
        return tree[rt].sum;
    }
    ll ans = 0;
    int mid = tree[rt].l + tree[rt].r >> 1;
    pushdown(rt);
    if (mid >= l) ans += query(rt << 1, l, r);
    if (mid + 1 <= r) ans += query(rt << 1 | 1, l, r);
    return ans;
}

void solve() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    build(1, 1, n);
    while (m--) {
        scanf("%s", opt);
        if (opt[0] == 'C') {
            ll l, r, val;
            l = read(), r = read(), val = read();
            update(1, l, r, val);
        }
        else {
            ll l, r;
            l = read(), r = read();
            printf("%lld\n", query(1, l, r));
        }
    }
}

int main() {
    solve();
    return 0;
}