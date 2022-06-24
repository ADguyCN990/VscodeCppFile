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
int n;
vector<int> g[MAXN];
int dis[MAXN];
int d[MAXN];
vector<int> fa[MAXN];
bool odd = false;
int rt;
void dfs(int now, int pre, int cnt) {
    if (d[now] == 1 && now != rt) {
        if (cnt & 1)
            odd = true;
        return;
    }
    for (int to : g[now]) {
        if (to == pre) continue;
        dfs(to, now, cnt + 1);
    }
}

void solve() {
    n = read();
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        d[u]++, d[v]++;
        g[u].pb(v), g[v].pb(u);
    }
    for (int i = 1; i <= n; i++)
        if (d[i] == 1 && !odd)
            rt = i, dfs(i, -1, 0);
    if (odd)
        printf("3 ");
    else
        printf("1 ");
    for (int i = 1; i <= n; i++) {
        if (d[i] == 1) {
            fa[g[i][0]].pb(i);
        }
    }
    int multi = 0;
    for (int i = 1; i <= n; i++) {
        multi += max(0, (int)(fa[i].size() - 2));
    }
    printf("%d\n", n - 1 - multi);
}

int main() {
    solve();
    return 0;
}