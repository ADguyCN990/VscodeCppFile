#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define MAXM 1000005
#define INF 0x3f3f3f3f
ll read() {};

typedef pair<int, int> pii;
struct EDGE {
    int to, next, val;  
}edge[MAXM];
int head[MAXN], tot;
void add(int from, int to, int val) {
    edge[++tot].to = to, edge[tot].val = val, edge[tot].next = head[from], head[from] = tot;
}
bool vis[MAXN];

int dis[5][MAXN]; //到三个原点的最短路
int n, m;

void dij(int s, int dis[]) {
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for (int i = 1; i <= n; i++) dis[i] = INF, vis[i] = false;
    dis[s] = 0;
    q.emplace(dis[s], s);
    while (q.size()) {
        int now = q.top().second;
        q.pop();
        if (vis[now]) continue;
        vis[now] = true;
        for (int i = head[now]; i; i = edge[i].next) {
            int to = edge[i].to;
            int val = edge[i].val;
            if (dis[to] > dis[now] + val) {
                dis[to] = dis[now] + val;
                q.emplace(dis[to], to);
            }
        }
    }
}


int main() {
    n = read(), m = read();
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        u = read(), v = read(), w = read();
        add(u, v, w);
        add(v, u, w);
    }
    dij(0, dis[0]), dij(1, dis[1]), dij(2, dis[2]);

}


ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}