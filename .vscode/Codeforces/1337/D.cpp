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
ll r[MAXN], g[MAXN], b[MAXN];
ll nr, ng, nb;
ll ans;

ll findmin(ll x, ll a[], ll len) {
    //a中最接近x的小于等于x的数
    int l = 1, r = len;
    int ans = -1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (a[mid] <= x) {
            ans = a[mid];
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return ans;
}

ll findmax(ll x, ll a[], ll len) {
    int l = 1, r = len;
    int ans = -1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (a[mid] >= x) {
            ans = a[mid];
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}

void work(ll a[], ll b[], ll c[], int alen, int blen, int clen) {
    for (int i = 1; i <= alen; i++) {
        ll mn = findmin(a[i], b, blen);
        ll mx = findmax(a[i], c, clen);
        if (mx == -1 || mn == -1) continue;
        ans = min(ans, (a[i] - mn) * (a[i] - mn) + (a[i] - mx) * (a[i] - mx) + (mx - mn) * (mx - mn));
    }
}

void solve() {
    nr = read(), ng = read(), nb = read();
    ans = INF;
    for (int i = 1; i <= nr; i++) r[i] = read();
    for (int i = 1; i <= ng; i++) g[i] = read();
    for (int i = 1; i <= nb; i++) b[i] = read();
    sort(r + 1, r + 1 + nr);
    sort(g + 1, g + 1 + ng);
    sort(b + 1, b + 1 + nb);
    work(r, g, b, nr, ng, nb);
    work(r, b, g, nr, nb, ng);
    work(g, r, b, ng, nr, nb);
    work(g, b, r, ng, nb, nr);
    work(b, g, r, nb, ng, nr);
    work(b, r, g, nb, nr, ng);
    printf("%lld\n", ans);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}