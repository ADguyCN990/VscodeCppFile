#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
#define MAXN 100005
#define MAXM 200005
#define INF 0x3f3f3f3f3f3f3f3f
ll dis[MAXN];
bool vis[MAXN];
int n, m;
int head[MAXN], tot;
typedef pair<int, int> pii;
struct EDGE {
    int to, next, val;
}edge[MAXM];

void add(int from, int to, int val) {
    edge[++tot].to = to, edge[tot].val = val, edge[tot].next = head[from], head[from] = tot;
}

void dij(int s) {
    for (int i = 1; i <= n; i++) dis[i] = INF;
    dis[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({dis[s], s});
    while (q.size()) {
        int now = q.top().second;
        q.pop();
        if (vis[now]) continue;
        vis[now] = true;
        for (int i = head[now]; i; i = edge[i].next) {
            int to = edge[i].to;
            ll val = edge[i].val;
            if (dis[to] > dis[now] + val) {
                dis[to] = dis[now] + val;
                q.push({dis[to], to});
            }
        }
    }
}

int main() {
    n = read(), m = read();
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        u = read(), v = read(), w = read();
        add(u, v, w), add(v, u, w);
    }
    dij(1);

    int t = read();
    while (t--) {
        int u = read(), v = read();
        printf("%lld\n", dis[u] + dis[v]);
    }
    return 0;
}