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
ll a[15];
int ans = 0;
void dfs(int now, int sum, int cnt) {
    if (sum >= k) {
        ans = max(ans, cnt);
        return;
    }
    if (now == n)
        return;
    dfs(now + 1, sum + a[now + 1], cnt + 1);
    dfs(now + 1, sum, cnt);
}

void solve() {
    n = read(), k = read();
    ans = 0;
    for (int i = 1; i <= n; i++) a[i] = read();
    sort(a + 1, a + 1 + n, greater<>());
    dfs(0, 0, 0);
    printf("%d\n", ans);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}