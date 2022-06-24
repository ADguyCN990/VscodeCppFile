#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
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
int n, k;
int a[MAXN];
bool vis[MAXN];
void solve() {
    n = read(), k = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    memset(vis, false, sizeof vis);
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (!vis[a[i]]) {
            vis[a[i]] = true;
            ans.pb(a[i]);
        }
    }
    if (ans.size() > k) {
        puts("-1");
        return;
    }
    for (int i = 1; i; i++) {
        if (vis[i]) continue;
        if (ans.size() == k) break;
        ans.pb(i);
    }
    printf("%d\n", n * k);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < k; j++)
            printf("%d ", ans[j]);
    puts("");
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}