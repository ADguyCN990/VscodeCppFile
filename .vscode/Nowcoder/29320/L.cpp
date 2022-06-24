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
ll n, k;
ll a[MAXN];
ll sum[MAXN];
void solve() {
    n = read(), k = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    int l = 1, r = 1;
    //[1,l-1] [l,r] [r+1,n]
    ll ans = 0;
    if (sum[n] < k) {
        printf("%lld\n", k - sum[n]);
        return;
    }
    while (1) {
        if (r == n + 1) {
            break;
        }
        if (sum[l - 1] + sum[n] - sum[r] < k && l <= r) {
            //printf("l: %d r: %d\n", l, r);
            //printf("add: %lld %lld sub: %lld\n", sum[l - 1], sum[n] - sum[r], sum[r] - sum[l - 1]);
            ans = max({ans, sum[l - 1] + sum[n] - sum[r] , 0ll});
            l++;
        }
        else
            r++;
    }
    printf("%lld\n", k - ans);
}

int main() {
    solve();
    return 0;
}