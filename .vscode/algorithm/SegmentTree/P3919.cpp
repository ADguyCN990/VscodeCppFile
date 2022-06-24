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

int rt[MAXN], idx;
int a[MAXN];
int n, m;
struct node {
    int l, r, val;
}tree[MAXN << 5];

int build(int l, int r) {
    int now = ++idx;
    if (l == r) {
        tree[now].val = a[l];
        return now;
    }
    int mid = l + r >> 1;
    tree[now].l = build(l, mid);
    tree[now].r = build(mid + 1, r);
    return now;
}

int update(int pre, int L, int R, int pos, int val) {
    int now = ++idx;
    tree[now] = tree[pre];
    if (L == R && L == pos) {
        tree[now].val = val;
        return now;
    }
    int mid = L + R >> 1;
    if (pos <= mid)  tree[now].l = update(tree[pre].l, L, mid, pos, val);
    else tree[now].r = update(tree[pre].r, mid + 1, R, pos, val);
    return now;
}

int query(int rt, int L, int R, int pos) {
    if (L == R) {
        return tree[rt].val;
    }
    int mid = L + R >> 1;
    if (pos <= mid) return query(tree[rt].l, L, mid, pos);
    else return query(tree[rt].r, mid + 1, R, pos);
}

int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    rt[0] = build(1, n);
    for (int i = 1; i <= m; i++) {
        int pre, opt, pos, val;
        pre = read(), opt = read(), pos = read();
        if (opt == 1) {
            val = read();
            rt[i] = update(rt[pre], 1, n, pos, val);
        }
        else {
            rt[i] = rt[pre];
            printf("%d\n", query(rt[pre], 1, n, pos));
        }
    }
    return 0;
}
