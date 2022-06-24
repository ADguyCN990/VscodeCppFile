#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
typedef pair<int, int> pii;
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int n, m, q;
int path[MAXN];
int dis[MAXN];
pii e[MAXN];
vector<int> g[MAXN];

void bfs(int s) {
    queue<int> q;
    for (int i = 1; i <= n; i++) dis[i] = -1;
    dis[s] = 0;
    q.push(s);
    while (q.size()) {
        int now = q.front();
        q.pop();
        for (int to : g[now]) {
            if (dis[to] != -1) continue;
            dis[to] = dis[now] + 1;
            q.push(to);
        }
    }
}

int main() {
    n = read(), m = read();
    for (int i = 1; i <= m; i++) {
        e[i].first = read(), e[i].second = read();
        g[e[i].second].push_back(e[i].first);
    }
    q = read();
    for (int i = 1; i <= q; i++) path[i] = read();
    bfs(path[q]);
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i <= m; i++) {
        int u = e[i].first, v = e[i].second;
        g[u].push_back(v);
    }
    int mn = 0, mx = 0;
    for (int i = 1; i < q; i++) {
        int now = path[i];
        int cnt = 0;
        bool flag = false;
        for (int to : g[now]) {
            if (dis[to] + 1 == dis[now]) {
                cnt++;
                if (to == path[i + 1]) flag = true;
            }
        }
        if (!flag)
            mx++, mn++;
        else if (flag && cnt > 1)
            mx++;
    }
    printf("%d %d\n", mn, mx);
    return 0;
}
