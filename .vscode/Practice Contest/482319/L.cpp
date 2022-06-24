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
int n, k;
char s[MAXN];
int sum[MAXN];
int dp[MAXN];
struct node {
    int l, r;
    int mn;
}tree[MAXN << 2];

void pushup(int rt) {
    tree[rt].mn = min(tree[rt << 1].mn, tree[rt << 1 | 1].mn);
}

void build(int rt, int l, int r) {
    tree[rt] = {l, r, INF};
    if (l == r)
        return;
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
}

void update(int rt, int pos, int val) {
    if (tree[rt].l == tree[rt].r) {
        tree[rt].mn = val;
        return;
    }
    int mid = tree[rt].l + tree[rt].r >> 1;
    if (pos <= mid) update(rt << 1, pos, val);
    if (mid + 1 <= pos) update(rt << 1 | 1, pos, val);
    pushup(rt);
}

int query(int rt, int l, int r) {
    if (tree[rt].l >= l && tree[rt].r <= r) {
        return tree[rt].mn;
    }
    int mid = tree[rt].l + tree[rt].r >> 1;
    int ans = INF;
    if (mid >= l) ans = min(ans, query(rt << 1, l, r));
    if (mid + 1 <= r) ans = min(ans, query(rt << 1 | 1, l, r));
    return ans;
}

void solve() {
    n = read(), k = read();
    scanf("%s", s + 1);
    //dp[i] = min({dp[j] + 1})
    build(1, 1, n);
    for (int i = 1; i <= n; i++) dp[i] = INF;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1];
        if (s[i] == s[i - 1]) sum[i]++; //出现了00或11
    }
    dp[0] = -1;
    //明确状态只能从00或11转移而来，否则就自增1
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + 1; //先假设要分段
        //[j, i]这段是合法的，状态就可以由j转移过来，j最小为i-k，最大为i-1
        if (i <= k) {
            if (sum[i]) //已经出现了00或11，说明这段是合法的
                update(1, i, 0), dp[i] = 0;
            else
                update(1, i, dp[i]);
            continue;
        }
        int l = i - k + 1, r = i - 1, pos = -1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (sum[mid] != sum[i]) {
                pos = mid;
                l = mid + 1;
            }
            else    
                r = mid - 1;
        }
        if (pos == -1)
            update(1, i, dp[i]);
        else {
            int tmp = query(1, i - k, pos - 1);
            dp[i] = tmp + 1;
            update(1, i, dp[i]);
        }
    }
    printf("%d\n", dp[n]);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}