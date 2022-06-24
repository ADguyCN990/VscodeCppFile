#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
#define MAXM 500005
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
bool vis[MAXN];
pii p[MAXM];
int n, m;
void solve() {
    n = read(), m = read();
    vector<int> edge;
    for (int i = 1; i <= 3 * n; i++) vis[i] = false;
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read();
        p[i].first = u, p[i].second = v;
        if (!vis[u] && !vis[v]) {
            edge.pb(i);
            vis[u] = true, vis[v] = true;
        }
    }
    if (edge.size() >= n) {
        puts("Matching");
        for (int i = 0; i < n; i++) printf("%d ", edge[i]);
        puts("");
        return;
    }
    puts("IndSet");
    for (int i = 1, cnt = 1; cnt <= n; i++) {
        if (!vis[i]) {
            printf("%d ", i);
            cnt++;
        }
    }
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