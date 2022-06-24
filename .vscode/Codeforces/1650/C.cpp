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
ll n, m;
ll x[MAXN], w[MAXN];

struct node {
    int val;
    int id;
    int pos;
}a[MAXN], b[MAXN];

bool cmp1(node a, node b) {return a.val < b.val;}
bool cmp2(node a, node b) {return a.pos < b.pos;}

void solve() {
    n = read(), m = read();
    for (int i = 1; i <= m; i++) {
        a[i].pos = read();
        a[i].val = read();
        a[i].id = i;
    }
    sort(a + 1, a + 1 + m, cmp1);
    ll ans = 0;
    for (int i = 1; i <= 2 * n; i++) {
        b[i] = a[i];
        ans += a[i].val;
    }
    sort(b + 1, b + 1 + 2 * n, cmp2);
    printf("%lld\n", ans);
    for (int i = 1, j = 2 * n; i < j; i++, j--) {
        printf("%d %d\n", b[i].id, b[j].id);
    }
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}