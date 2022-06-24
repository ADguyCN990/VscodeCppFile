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
int a[MAXN], b[MAXN];
int d[MAXN];
void solve() {
    n = read(), k = read();
    ll ans = 0;
    for (int i = 1; i <= n; i++) a[i] = read(), ans += a[i];
    for (int i = 1; i <= n; i++) b[i] = read(), d[i] = a[i] - b[i];
    sort(d + 1, d + 1 + n, greater<>());
    ll dif = 0;
    for (int i = 1; i <= k; i++) {
        if (d[i] < 0) {
            break;
        }
        dif += d[i];
    }
    printf("%lld\n", ans - dif);
}

int main() {
    solve();
    return 0;
}