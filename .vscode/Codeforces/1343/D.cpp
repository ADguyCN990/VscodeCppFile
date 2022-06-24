#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 400005
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
ll n, k;
ll a[MAXN];
struct node {
    int l, r, len;
    ll add, sum;
}tree[MAXN << 2];

void pushup(int rt) {
    tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum;
}

void build(int rt, int l, int r) {
    tree[rt] = {l, r, r - l + 1, 0, 0};
    if (l == r) {
        return;
    }
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
}

void pushdown(int rt) {
    if (tree[rt].add) {
        tree[rt << 1].sum += tree[rt].add * tree[rt << 1].len;
        tree[rt << 1 | 1].sum += tree[rt].add * tree[rt << 1 | 1].len;
        tree[rt << 1].add += tree[rt].add;
        tree[rt << 1 | 1].add += tree[rt].add;
        tree[rt].add = 0;
    }
    
}

void update(int rt, int l, int r, int add) {
    if (tree[rt].l >= l && tree[rt].r <= r) {
        tree[rt].sum += tree[rt].len * add;
        tree[rt].add += add;
        return;
    }
    pushdown(rt);
    int mid = tree[rt].l + tree[rt].r >> 1;
    if (mid >= l) update(rt << 1, l, r, add);
    if (mid + 1 <= r) update(rt << 1 | 1, l, r, add);
    pushup(rt);
}

ll query(int rt, int l, int r) {
    if (tree[rt].l >= l && tree[rt].r <= r) {
        return tree[rt].sum;
    }
    pushdown(rt);
    int mid = tree[rt].l + tree[rt].r >> 1;
    ll ans = 0;
    if (mid >= l) ans += query(rt << 1, l, r);
    if (mid + 1 <= r) ans += query(rt << 1 | 1, l, r);
    return ans;
}

void solve() {
    n = read(), k = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    build(1, 1, 2 * k);
    for (int i = 1; i <= n / 2; i++) {
        int x = a[i];
        int y = a[n - i + 1];
        update(1, 1, 2 * k, 2);
        int mn = max(1, min(x, y) + 1);
        int mx = min(2 * k, max(x, y) + k);
        update(1, mn, mx, -1);
        update(1, x + y, x + y, -1);
    }
    ll mn = INF;
    for (int i = 1; i <= 2 * k; i++)
        mn = min(mn, query(1, i, i));
    printf("%lld\n", mn);
    
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}