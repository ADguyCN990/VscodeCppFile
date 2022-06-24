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
ll n, m;
vector<ll> mp[MAXN];
int cnt[MAXN];
ll lth[MAXN];
void solve() {
    ll ans = 0;
    n = read(), m = read();
    for (int i = 1; i <= n; i++) {
        mp[i].push_back(0);
        for (int j = 1; j <= m; j++) {
            int x;
            scanf("%d", &x);
            mp[i].push_back(x);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int c = mp[i][j];
            ans += lth[c] - 1ll * cnt[c] * (n - i);
            lth[c] += n - i;
            cnt[c]++;
        }
    }
    memset(lth, 0, sizeof lth);
    memset(cnt, 0, sizeof cnt);
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            int c = mp[i][j];
            ans += lth[c] - 1ll * cnt[c] * (m - j);
            lth[c] += m - j;
            cnt[c]++;
        }
    }
    printf("%lld", ans);
}

int main() {
    solve();
    return 0;
}