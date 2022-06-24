#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 405
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
ll n;
ll a[MAXN];
ll mx[MAXN][MAXN], mn[MAXN][MAXN];
ll sum[MAXN];
void solve() {
    n = read();
    for (int i = 1; i < n; i++) {
        a[i] = read();
        a[i + n] = a[i];
    }
    a[n] = read();
    ll N = 2 * n - 1;
    for (int i = 1; i <= N; i++) sum[i] = sum[i - 1] + a[i];
    memset(mn, 0x3f, sizeof mn);
    memset(mx, ~0x3f, sizeof mx);
    for (int len = 1; len <= n; len++) {
        for (int l = 1, r; r = l + len - 1, r <= N; l++) {
            if (l == r) {
                mn[l][r] = 0;
                mx[l][r] = 0;
            }
            else {
                for (int k = l; k < r; k++) {
                    //[l,k] [k+1,r]
                    mx[l][r] = max(mx[l][k] + mx[k + 1][r] + sum[r] - sum[l - 1], mx[l][r]);
                    mn[l][r] = min(mn[l][k] + mn[k + 1][r] + sum[r] - sum[l - 1], mn[l][r]);
                }
            }
        }
    }
    ll MN = INF, MX = -INF;
    for (int i = 1; i <= n; i++) {
        MN = min(MN, mn[i][i + n - 1]);
        MX = max(MX, mx[i][i + n - 1]);
    }
    printf("%lld\n%lld\n", MN, MX);
}

int main() {
    solve();
    return 0;
}