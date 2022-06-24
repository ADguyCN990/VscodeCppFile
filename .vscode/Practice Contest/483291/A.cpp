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
ll n, f[2][MAXN], siz[2][MAXN];

int findx(ll *f, int x) { 
    if (x == f[x]) return x;
    return f[x] = findx(f, f[x]);
}

void merge( int x, int y, ll *f, ll *siz)
{
    int u = findx(f, x), v = findx(f, y);
    if(u != v) {
        f[u] = v;
        siz[v] += siz[u];
    }
}


void solve() {
    int n = read();
    for (int i = 1; i <= n; i++) {
        siz[0][i] = 1;
        siz[1][i] = 1;
        f[0][i] = i;
        f[1][i] = i;
    }
    for (int i = 1; i < n; i++) {
        int u = read(), v = read(), w = read();
        merge(u, v, f[w], siz[w]);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int now = findx(f[0], i);
        int noww = findx(f[1], i);
        ans += siz[0][now] * siz[1][noww] - 1;
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}