#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define MAXM 200005
#define ll long long
typedef pair<int, int> pii;
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

int n;
int d[MAXN];
int color[MAXN];
vector<int> g[MAXN];
map<pii, int> edge;
int cnt = 0;

int main() {
    n = read();
    memset(color, -1, sizeof color);
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        g[u].push_back(v);
        g[v].push_back(u);
        d[u]++, d[v]++;
        cnt++;
        edge[{u, v}] = cnt, edge[{v, u}] = cnt;
    }
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        if (d[i] >= 3) {
            flag = true;
            for (int j = 0; j < 3; j++) {
                int to = g[i][j];
                int idx = edge[{i, to}];
                color[idx] = j;
            }
            break;
        }
    }
    if (!flag) {
        for (int i = 1; i < n; i++) printf("%d\n", i - 1);
        return 0;
    }
    int now = 2;
    for (int i = 1; i < n; i++) {
        if (color[i] == -1) {
            color[i] = ++now;
        }
    }
    for (int i = 1; i < n; i++)
        printf("%d\n", color[i]);
    return 0;
}