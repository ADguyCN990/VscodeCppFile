#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
int read() {
    int x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int n, c;
int ans1, ans2;
int a[MAXN];
struct node {
    int l, r, mx;
}tree[MAXN << 2];

void pushup(int rt) {
    tree[rt].mx = max(tree[rt << 1].mx, tree[rt << 1 | 1].mx);
}

void build(int rt, int l, int r) {
    tree[rt].l = l, tree[rt].r = r;
    if (l == r) {
        tree[rt].mx = c;
        return;
    }
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}

void update(int rt, int val) {
    if (tree[rt].l == tree[rt].r) {
        ans1 = max(ans1, tree[rt].l);
        tree[rt].mx -= val;
        return;
    }
    int mid = tree[rt].l + tree[rt].r >> 1;
    if (tree[rt << 1].mx >= val) update(rt << 1, val);
    else update(rt << 1 | 1, val);
    pushup(rt);
}

void init() {
    ans1 = 0;
    ans2 = 0;
}

void solve() {
    n = read(), c = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    build(1, 1, n);
    init();
    for (int i = 1; i <= n; i++) {
        update(1, a[i]);
    }
    multiset<int> se;
    for (int i = 1; i <= n; i++) {
        auto pos = se.lower_bound(a[i]);
        if (pos == se.end()) {
            se.insert(c - a[i]);
        }
        else {
            auto tmp = pos;
            se.erase(pos);
            int val = *tmp - a[i];
            se.insert(val);
        }
    }
    ans2 = se.size();
    printf("%d %d\n", ans1, ans2);
}

int main() {
    int t = read();
    while (t--)
        solve();
    return 0;
}