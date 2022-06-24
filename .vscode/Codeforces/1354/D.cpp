#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
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
int n, q;
struct node {
    int sum;
}tree[MAXN << 2];

void pushup(int rt) {
    tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum;
}

void update(int rt, int pos, int l, int r, int val) {
    if (l == r && l == pos) {
        tree[rt].sum += val;
        return;
    }
    int mid = l + r >> 1;
    if (pos <= mid) update(rt << 1, pos, l, mid, val);
    if (pos >= mid + 1) update(rt << 1 | 1, pos, mid + 1, r, val);
    pushup(rt);
}

int kth(int rt, int l, int r, int k) {
    if (l == r) return l;
    int mid = l + r >> 1;
    if (tree[rt << 1].sum >= k) return kth(rt << 1, l, mid, k);
    else return kth(rt << 1 | 1, mid + 1, r, k - tree[rt << 1].sum);
}

int query(int rt, int l, int r) {
    if (l == r) {
        return l;
    }
    int mid = l + r >> 1;
    if (tree[rt << 1].sum > 0) return query(rt << 1, l, mid);
    else return query(rt << 1 | 1, mid + 1, r);
}

void solve() {
    n = read(), q = read();
    for (int i = 1; i <= n; i++) {
        int x = read();
        update(1, x, 1, n, 1);
    }
    for (int i = 1; i <= q; i++) {
        int opt = read();
        if (opt < 0) {
            opt = -opt;
            int num = kth(1, 1, n, opt);
            //printf("%d\n", num);
            update(1, num, 1, n, -1);
        }
        else if (opt > 0) {
            update(1, opt, 1, n, 1);
        }
    }
    //printf("%d\n", tree[1].sum);
    if (tree[1].sum == 0) {
        puts("0");
    }
    else {
        printf("%d\n", query(1, 1, n));
    }
}

int main() {
    solve();
    return 0;
}