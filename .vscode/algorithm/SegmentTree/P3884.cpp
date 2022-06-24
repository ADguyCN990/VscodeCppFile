#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long
int read() {
    int x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
vector<int> num;
int find(int x) {
    return lower_bound(num.begin(), num.end(), x) - num.begin() + 1;
}

struct node {
    int l, r, cnt;
}tree[MAXN << 5];

int rt[MAXN], idx;
int a[MAXN];
int n, m;

int build(int l, int r) {
    int now = ++idx;
    tree[now].cnt = 0;
    if (l < r) {
        int mid = l + r >> 1;
        tree[now].l = build(l, mid);
        tree[now].r = build(mid + 1, r);
        return now;
    }
    return now;
}

int update(int pre, int L, int R, int pos) {
    int now = ++idx;
    tree[now] = tree[pre];
    tree[now].cnt++;
    if (L < R) {
        int mid = L + R >> 1;
        if (pos <= mid) tree[now].l = update(tree[pre].l, L, mid, pos);
        else tree[now].r = update(tree[pre].r, mid + 1, R, pos);
        return now;
    }
    return now;
}

int query(int pre, int now, int L, int R, int k) {
    if (L == R) {
        return L;
    }
    int mid = L + R >> 1;
    int dif = tree[tree[now].l].cnt - tree[tree[pre].l].cnt;
    if (k > dif) {
        return query(tree[pre].r, tree[now].r, mid + 1, R, k - dif);
    }
    else {
        return query(tree[pre].l, tree[now].l, L, mid, k);
    }

}

int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) a[i] = read(), num.push_back(a[i]);
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    int len = num.size();
    rt[0] = build(1, len);

    for (int i = 1; i <= n; i++) {
        rt[i] = update(rt[i - 1], 1, len, find(a[i]));
    }
    for (int i = 1; i <= m; i++) {
        int l = read(), r = read(), k = read();
        int pos = query(rt[l - 1], rt[r], 1, len, k);
        printf("%d\n", num[pos - 1]);
    }
    return 0;
}