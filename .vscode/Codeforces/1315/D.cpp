#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
map<ll, ll> f;
ll n;

struct node {
    ll id;
    ll val;
    friend bool operator< (node a, node b) {
        return a.val > b.val;
    }
}a[MAXN];

ll findx(ll x) {
    if (f[x] == 0 || x == f[x]) return f[x] = x;
    return f[x] = findx(f[x]);
}

void merge(ll x, ll y) {
    ll fx = findx(x);
    ll fy = findx(y);
    if (fx != fy)
        f[fy] = fx;
}

int main() {
    scanf("%lld", &n);
    f.clear();
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i].id);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i].val);
    sort(a + 1, a + 1 + n);
    //for (int i = 1; i <= 200000; i++) f[i] = i;
    // for (int i = 1; i <= n; i++) {
    //     printf("id: %d val: %d\n", a[i].id, a[i].val);
    // }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll fa = findx(a[i].id);
        //printf("id: %d fa: %d\n", a[i].id, fa);
        ans += (fa - a[i].id) * a[i].val;
        merge(fa + 1, fa);
    }
    
    printf("%lld\n", ans);
    return 0;
}