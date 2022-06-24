#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 1000005
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
ll n, GOAL, V;
ll s[MAXN], v[MAXN];
ll dp[MAXM]; //用i个Q币能达到的最多方案数
void solve() {
    n = read(), GOAL = read();
    for (int i = 1; i <= n; i++) s[i] = read();
    for (int i = 1; i <= n; i++) v[i] = read();
    for (int i = 1; i <= n; i++) V += s[i] * v[i];
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = V; j >= 0; j--) {
            for (int k = 0; k <= s[i]; k++) {
                dp[j] = max(dp[j - v[i] * k] * k, dp[j]);
            }
        }
    }
    for (int i = 1; i; i++) {
        if (dp[i] >= GOAL) {
            printf("%d\n", i);
            return;
        }
    }
}

int main() {
    solve();
    return 0;
}