#include<bits/stdc++.h>
using namespace std;
#define MAXN 1005
#define ll long long
typedef pair<int, int> pii;
pii edge[MAXN];
bool vis[MAXN];
int d[MAXN];
int n;

int query(int u, int v) {
    cout << "? " << u << " " << v << endl;
    int ans;
    cin >> ans;
    return ans;
}

void output(int x) {
    cout << "! " << x << endl;
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> edge[i].first >> edge[i].second;
    }
    for (int i = 1; i <= n / 2; i++) {
        queue<int> q;
        for (int i = 1; i <= n; i++) d[i] = 0;
        for (int i = 1; i < n; i++) {
            if (vis[edge[i].first] || vis[edge[i].second]) continue;
            d[edge[i].first]++, d[edge[i].second]++;
        }
        for (int i = 1; i <= n; i++)
            if (d[i] == 1 && !vis[i])
                q.push(i);
        if (q.size() == 1) {
            output(q.front());
            return 0;
        }
        int u = q.front(); q.pop();
        int v = q.front(); q.pop();
        int rt = query(u, v);
        if (rt == u || rt == v) {
            output(rt);
            return 0;
        }
        vis[u] = true, vis[v] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            output(i);
            return 0;
        }
    }
    return 0;
}