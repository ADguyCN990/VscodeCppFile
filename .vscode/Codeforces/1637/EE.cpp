#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
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
vector<pii> bad;
unordered_map<int, int> cnt;
vector<int> val[MAXN];
int n, m;
ll ans;

void init () {
    bad.clear();
    cnt.clear();
    ans = 0;
    for (int i = 0; i <= n; i++) val[i].clear();
}

void solve() {
    n = read(), m = read();
    init();
    for (int i = 1; i <= n; i++) {
        int x = read();
        cnt[x] ++;
    }
    for (auto it : cnt) 
        val[it.second].pb(it.first);
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read();
        bad.pb(u, v);
        bad.pb(v, u);
    }
    sort(bad.begin(), bad.end());
    for (int i = 0; i <= n; i++) {
        sort(val[i].begin(), val[i].end(), greater<>());
    }
    //通过枚举次数+预处理次数映射值的方法暴力求解
    for (int i = n; i >= 1; i--) {
        for (auto x : val[i]) {
            for (int j = i; j >= 1; j--) {
                for (auto y : val[j]) {
                    pii tmp = {x, y};
                    auto it = lower_bound(bad.begin(), bad.end(), tmp);
                    if (x != y && (it == bad.end() || *it != tmp)) {
                        ans = max(ans, 1ll * (x + y) * (i + j));
                        break;
                    }
                }
            }
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}