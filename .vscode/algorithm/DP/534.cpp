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
ll a[105];
ll dp[25005];
int V = 25000;

void solve() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    sort(a + 1, a + 1 + n);
    memset(dp, 0, sizeof dp);
    int cnt = 0;
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
        int now = a[i];
        if (!dp[now]) {
            cnt++;
        }
        else {
            continue;
        }
        for (int j = 0; j <= 25000 - a[i]; j++)
            dp[j + a[i]] |= dp[j];
    }
    printf("%d\n", cnt);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}