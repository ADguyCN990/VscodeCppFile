#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 35
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
int n, m;
int a[MAXN][MAXN];
int cnt[MAXN + MAXN][2];

void solve() {
    n = read(), m = read();
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = read(), cnt[i + j - 1][a[i][j]]++;
    int l = 1, r = m + n - 1;
    int ans = 0;
    while (l < r) {
        ans += min(cnt[l][0] + cnt[r][0], cnt[l][1] + cnt[r][1]);
        l++, r--;
    }
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