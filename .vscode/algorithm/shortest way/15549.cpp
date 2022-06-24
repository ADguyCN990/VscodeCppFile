#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 400005
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f3f3f3f3f
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
ll dis[MAXN];
int head[MAXN];int tot;
struct EDGE {
    int to, next, val;
}edge[MAXM];
struct node {
    int id;
    ll val;
    friend bool operator < (node a, node b) {
        return a.val > b.val;
    }
};
void add_edge(int from,int to,int val) {
    edge[++tot].to = to; edge[tot].val = val; edge[tot].next = head[from]; head[from] = tot;
}
int n, m;

void dij(int s) {
    for (int i = 1; i <= n; i++) dis[i] = INF, vis[i] = false;
    dis[s] = 0;
    priority_queue <node> q;
    q.push(node{s, dis[s]});
    while (q.size()) {
        int now = q.top().id;
        q.pop();
        if (vis[now]) continue;
        vis[now] = true;
        for (int i = head[now]; i; i = edge[i].next) {
            int to = edge[i].to;
            ll val = edge[i].val;
            if (dis[to] > dis[now] + val) {
                dis[to] = dis[now] + val;
                q.push(node{to, dis[to]});
            }
        }
    }   
}

void solve() {
    n = read(), m = read();
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        u = read(), v = read(), w = read();
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    dij(1);
    if (dis[n] == INF) 
        puts("qwb baka");
    else 
        printf("%lld\n", dis[n]);
}

int main() {
    solve();
    return 0;
}