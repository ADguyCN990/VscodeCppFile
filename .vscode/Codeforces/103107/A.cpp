#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 400005
struct node {
    int l, r, mx, f;
}tree[MAXN << 2];
int n, m;
int a[MAXN];

void pushup(int rt) {
    tree[rt].mx = max(tree[rt << 1].mx, tree[rt << 1 | 1].mx);
    tree[rt].f = tree[rt << 1].f | tree[rt << 1 | 1].f;
}

void build(int rt, int l, int r) {
    tree[rt].l = l, tree[rt].r = r;
    if (l == r) {
        tree[rt].mx = a[l];
        tree[rt].f = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}

int query(int rt, int l, int r) {
    if (tree[rt].l >= l && tree[rt].r <= r) {
        return tree[rt].mx;
    }
    int mid = tree[rt].l + tree[rt].r >> 1;
    int ans = 0;
    if (mid >= l) ans = query(rt << 1, l, r);
    if (mid + 1 <= r) ans = max(ans, query(rt << 1 | 1, l, r));
    return ans;
}

void AND(int rt, int l, int r, int val) {
    if (tree[rt].l == tree[rt].r) {
        tree[rt].mx = tree[rt].mx & val;
        tree[rt].f = tree[rt].f & val;
        return;
    }
    int mid = tree[rt].l + tree[rt].r >> 1;
    if (mid >= l && (val & tree[rt << 1].f) < tree[rt << 1].f) AND(rt << 1, l, r, val);
    if (mid + 1 <= r && (val & tree[rt << 1 | 1].f) < tree[rt << 1 | 1].f) AND(rt << 1 | 1, l, r, val);
    pushup(rt); 
}

void change(int rt, int pos, int val) {
    if (tree[rt].l == tree[rt].r) {
        tree[rt].mx = val;
        tree[rt].f = val;
        return;
    }
    int mid = tree[rt].l + tree[rt].r >> 1;
    if (mid >= pos) change(rt << 1, pos, val);
    if (mid + 1 <= pos) change(rt << 1 | 1, pos, val);
    pushup(rt);
}

char s[10];
int l, r, val;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    build(1, 1, n);
    while (m--) {
        scanf("%s", s);
        if (s[0] == 'A') {
            scanf("%d%d%d", &l, &r, &val);
            AND(1, l, r, val);
        }
        else if (s[0] == 'U') {
            scanf("%d%d", &l, &val);
            change(1, l, val);
        }
        else {
            scanf("%d%d", &l, &r);
            printf("%d\n", query(1, l, r));
        }
    }
    return 0;
}