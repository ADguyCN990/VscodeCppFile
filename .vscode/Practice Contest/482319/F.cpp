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

struct node {
    int u, v, w;
    friend bool operator< (node a, node b) {
        return a.w < b.w;
    }
}a[MAXN];
int n, m;
int f[MAXN];
int findx(int x) {
    if (x == f[x]) return x;
    return f[x] = findx(f[x]);
}
void merge(int x, int y) {
    int fx = findx(x);
    int fy = findx(y);
    if (fx != fy)
        f[fy] = fx;
}

void solve() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) f[i] = i;
    for (int i = 1; i <= m; i++) {
        a[i].u = read(), a[i].v = read(), a[i].w = read();
    }
    sort(a + 1, a + 1 + m);
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int u = a[i].u, v = a[i].v, w = a[i].w;
        
        if (findx(u) != findx(v)) {
            merge(u, v);
            ans = w;
        }
    }
    printf("%d\n", ans);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}