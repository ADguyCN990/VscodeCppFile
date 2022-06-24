#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
#define MAXM 40005
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
ll n, GOAL;
ll v[MAXN], s[MAXN];
ll dp1[MAXM], dp2[MAXM]; //凑出i元最少要几个硬币
void solve() {
    n = read(), GOAL = read();
    ll MAX = 0;
    for (int i = 1; i <= n; i++) v[i] = read();
    for (int i = 1; i <= n; i++) s[i] = read(), MAX += v[i] * s[i];
    if (MAX < GOAL) {
        puts("-1");
        return;
    }
    memset(dp1, 0x3f, sizeof dp1);
    memset(dp2, 0x3f, sizeof dp2);
    dp1[0] = 0, dp2[0] = 0;
    ll V = 40000;
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= s[i]; k *= 2) {
            for (int j = V; j >= k * v[i]; j--) {
                //if (j == k * v[i] || dp1[j - k * v[i]])
                    dp1[j] = min(dp1[j], dp1[j - k * v[i]] + k);
            }
            s[i] -= k;
        }
        if (s[i]) {
            for (int j = V; j >= s[i] * v[i]; j--) {
                //if (j == s[i] * v[i] || dp1[j - s[i] * v[i]])
                dp1[j] = min(dp1[j], dp1[j - s[i] * v[i]] + s[i]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = v[i]; j <= V - GOAL; j++) {
            dp2[j] = min(dp2[j], dp2[j - v[i]] + 1);
        }
    }
    ll ans = INF;
    for (int i = GOAL; i <= V; i++) {
        ll num1 = dp1[i];
        ll num2 = dp2[i - GOAL];
        if (num1 + num2 < ans) {
            //printf("num1: %lld num2: %lld i: %d\n", num1, num2, i);
            ans = num1 + num2;
        }
    }
    if (ans == INF) {
        puts("-1");
        return;
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}