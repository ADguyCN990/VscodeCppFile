#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
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
ll n;
ll a[MAXN], b[MAXN];
bool dp[105][10005];
void solve() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) b[i] = read();
    if (n == 1) {
        puts("0");
        return;
    }
    ll ans = 0;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        ans += (a[i] * a[i] + b[i] * b[i]); 
        sum += a[i] + b[i];
    }
    ans *= (n - 2);
    //printf("ans: %lld\n", ans);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= 10000; j++)
            dp[i][j] = false;
    dp[1][a[1]] = true, dp[1][b[1]] = true;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 10000; j++) {
            if (dp[i - 1][j]) {
                dp[i][j + a[i]] = true;
                dp[i][j + b[i]] = true;
            }
        }
    }
    ll tmp = INF;
    for (int i = 0; i <= 10000; i++) {
        if (dp[n][i] == true) {
            tmp = min(tmp, i * i + (sum - i) * (sum - i));
        }
    }
    printf("%lld\n", tmp + ans);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}