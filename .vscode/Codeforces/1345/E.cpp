#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 400005
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
int n, m;
vector<int> pos[MAXN]; //正向边，小于
vector<int> neg[MAXN]; //反向边，大于

int indgr[MAXN];
char ans[MAXN];
int pre[MAXN], nxt[MAXN]; //最小前驱，最小后继的编号（在拓扑序上做DP）
vector<int> top;

bool topu() {
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!indgr[i])
            q.push(i);
    while (q.size()) {
        int now = q.front();
        q.pop();
        top.pb(now);
        for (int to : pos[now]) {

            indgr[to]--;
            if (!indgr[to])
                q.push(to);
        }
    }
    return top.size() == n;
}

void solve() {
    n = read(), m = read();
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read();
        pos[u].pb(v);//正向边
        neg[v].pb(u);//反向边
        indgr[v]++;
    }
    bool flag = topu();
    if (!flag) {
        puts("-1");
        return;
    }
    for (int i = 1; i <= n; i++) nxt[i] = i, pre[i] = i;
    for (int i = 0; i < n; i++) {
        int now = top[i];
        for (int to : neg[now]) {
            pre[now] = min(pre[now], pre[to]);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        int now = top[i];
        for (int to : pos[now]) {
            nxt[now] = min(nxt[now], nxt[to]);
        }
    }
    puts("pre:");
    for (int i = 1; i <= n; i++) printf("%d ", pre[i]);
    puts("");
    puts("nxt:");
    for (int i = 1; i <= n; i++) printf("%d ", nxt[i]);
    puts("");
    for (int i = 1; i <= n; i++) ans[i] = 'E';
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (min(pre[i], nxt[i]) == i)
            cnt++, ans[i] = 'A';
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= n; i++) printf("%c", ans[i]);
    puts("");
}

int main() {
    solve();
    return 0;
}