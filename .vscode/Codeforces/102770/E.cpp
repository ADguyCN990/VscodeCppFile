#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll pingfang[MAXN];
int read() {
    int x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
void prework() {
    for (ll i = 1; i <= 100000; i++) {
        pingfang[i] = pingfang[i - 1] + i * i;
    }
}
int n, m;
int a[MAXN];
vector<int> num;
int rt[MAXN], idx = 0;
struct node {
    int l, r, cnt;
    ll val;
}tree[MAXN << 5];
int find(int x) {
    return lower_bound(num.begin(), num.end(), x) - num.begin() + 1;
}

void init() {
    num.clear();
    idx = 0;
}

int build(int l, int r) {
    int now = ++idx;
    int mid = l + r >> 1;
    if (l < r) {
        tree[now].l = build(l, mid);
        tree[now].r = build(mid + 1, r);
    }
    tree[now].cnt = 0;
    tree[now].val = 0;
    return now;
}

int update(int pre, int L, int R, int pos, int val) {
    int now = ++idx;
    tree[now] = tree[pre];
    tree[now].cnt++, tree[now].val += val;
    int mid = L + R >> 1;
    if (L < R) {
        if (pos <= mid) tree[now].l = update(tree[pre].l, L, mid, pos, val);
        else tree[now].r = update(tree[pre].r, mid + 1, R, pos, val);
    }
    return now;
}

ll query(int l, int r, int L, int R, int k) {
    //区间内最大k个数的和
    if (L == R) return k * num[L - 1];
    int mid = L + R >> 1;
    int sum = tree[tree[r].r].cnt - tree[tree[l].r].cnt;
    ll val = tree[tree[r].r].val - tree[tree[l].r].val;
    //sum表示这段区间右部分插入的数
    if (sum >= k)
        return query(tree[l].r, tree[r].r, mid + 1, R, k);
    else
        return val + query(tree[l].l, tree[r].l, L, mid, k - sum);

}

void solve() {
    n = read();
    init();
    for (int i = 1; i <= n; i++) {
        rt[i] = 0;
        a[i] = read();
        num.push_back(a[i]);
    }
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    int len = num.size();
    rt[0] = build(1, len);
    for (int i = 1; i <= n; i++)
        rt[i] = update(rt[i - 1], 1, len, find(a[i]), a[i]);
    m = read();
    while (m--) {
        int l = read(), r = read(), k = read();
        ll ans = pingfang[r - l + 1] + query(rt[l - 1], rt[r], 1, len, k);
        printf("%lld\n", ans);
    }
}

int main() {
    prework();
    int t = read();
    while (t--)
        solve();
    return 0;
}