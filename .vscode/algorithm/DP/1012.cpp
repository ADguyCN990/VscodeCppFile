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
ll n;
ll a[MAXN];
ll dp1[MAXN];
ll dp2[MAXN];
void solve() {
    n = 0;
    ll tmp;
    while (scanf("%lld", &tmp) != EOF) {
        ++n;
        a[n] = tmp;
    }
    ll ans1 = 0;
    dp1[1] = 1;
    for (int i = 2; i <= n; i++) {
        ll mx = 0;
        for (int j = 1; j < i; j++) 
            if (a[j] >= a[i])
                mx = max(mx, dp1[j]);
        dp1[i] = mx + 1;
    }
    for (int i = 1; i <= n; i++) ans1 = max(ans1, dp1[i]);
    printf("%lld\n", ans1);
    dp2[1] = 1;
    for (int i = 2; i <= n; i++) {
        ll mx = 0;
        for (int j = 1; j < i; j++) 
            if (a[j] < a[i])
                mx = max(mx, dp2[j]);
        dp2[i] = mx + 1;
    }
    ll ans2 = 0;
    for (int i = 1; i <= n; i++) ans2 = max(ans2, dp2[i]);
    printf("%lld\n", ans2);
}

int main() {
    solve();
    return 0;
}