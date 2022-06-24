#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f3f3f3f3f
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define per(i, x, y) for(int i = x; i >= y; i--)
#define pb emplace_back
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
ll n, q, a, b;
ll x[MAXN];
struct node {
    int l, r;
    ll val1; //dp[i]
    ll val2; //dp[i] - i
    ll val3; //dp[i] + i
    ll add;
}tree[MAXN << 2]; //权值线段树优化DP

void addall(ll add) { 
    tree[1].add += add, tree[1].val1 += add, tree[1].val2 += add, tree[1].val3 += add;
}

void pushup(int rt) {
    tree[rt].val1 = min(tree[rt << 1].val1, tree[rt << 1 | 1].val1);
    tree[rt].val2 = min(tree[rt << 1].val2, tree[rt << 1 | 1].val2);
    tree[rt].val3 = min(tree[rt << 1].val3, tree[rt << 1 | 1].val3);
}

void pushdown(int rt) {
    if (tree[rt].add) {
        tree[rt << 1].val1 += tree[rt].add;
        tree[rt << 1 | 1].val1 += tree[rt].add;
        tree[rt << 1].val2 += tree[rt].add;
        tree[rt << 1 | 1].val2 += tree[rt].add;
        tree[rt << 1].val3 += tree[rt].add;
        tree[rt << 1 | 1].val3 += tree[rt].add;
        tree[rt << 1].add += tree[rt].add;
        tree[rt << 1 | 1].add += tree[rt].add;
        tree[rt].add = 0;
    }
}

void build(int rt, int l, int r) {
    tree[rt] = {l, r, INF, INF, INF, 0};
    if (l == r) return;
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
}

void update(int rt, int pos, ll val) {
    //单点修改
    if (tree[rt].l == tree[rt].r && tree[rt].l == pos) {
        tree[rt].val1 = val;
        tree[rt].val2 = val - pos;
        tree[rt].val3 = val + pos;
        return;
    }
    pushdown(rt);
    int mid = tree[rt].l + tree[rt].r >> 1;
    if (mid >= pos) update(rt << 1, pos, val);
    if (mid + 1 <= pos) update(rt << 1 | 1, pos, val);
    pushup(rt);
}

ll query2(int rt, int l, int r) {
    //查询dp[k] - k
    if (tree[rt].l >= l && tree[rt].r <= r) {
        return tree[rt].val2;
    }
    pushdown(rt);
    int mid = tree[rt].l + tree[rt].r >> 1;
    ll ans = INF;
    if (mid >= l) ans = min(ans, query2(rt << 1, l, r));
    if (mid + 1 <= r) ans = min(ans, query2(rt << 1 | 1, l, r));
    return ans;
}

ll query3(int rt, int l, int r) {
    //查询dp[k] + k
    if (tree[rt].l >= l && tree[rt].r <= r) {
        return tree[rt].val3;
    }
    pushdown(rt);
    int mid = tree[rt].l + tree[rt].r >> 1;
    ll ans = INF;
    if (mid >= l) ans = min(ans, query3(rt << 1, l, r));
    if (mid + 1 <= r) ans = min(ans, query3(rt << 1 | 1, l, r));
    return ans;
}

void solve() {
    n = read(), q = read(), a = read(), b = read();
    for (int i = 1; i <= q; i++) x[i] = read();
    build(1, 1, n);
    //状态定义为，现在是第i个操作，有一个棋子在x[i]上，另一个棋子位于j上，dp[i][j]表示这样状态的最小操作步数

    //状态初始化，把a移动到x[1]上
    update(1, b, abs(a - x[1]));
    //状态初始化，把b移动到x[1]上
    update(1, a, abs(b - x[1]));

    for (int i = 2; i <= q; i++) {
        int now = x[i];
        int pre = x[i - 1];
        ll dif = abs(now - pre); //连续移动时需要的步数
        ll ans1 = query2(1, 1, now) + now;
        ll ans2 = query3(1, now + 1, n) - now;
        ll ans = min(ans1, ans2);

        addall(dif); //和下面一行先手顺序不能调
        update(1, pre, ans); //pre这个值是假的，要被重新更新掉
    }
    printf("%lld\n", tree[1].val1);

}

int main() {
    solve();
    return 0;
}