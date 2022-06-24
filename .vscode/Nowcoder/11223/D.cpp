#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
#define MAXM 2000005
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
int dis1[MAXN], dis2[MAXN];
int ans[MAXN];
int head[MAXN], tot;
vector<int> one[MAXN];
struct EDGE {
    int to, next, val;
}edge[MAXM];
void add(int from, int to, int val) {
    edge[++tot].to = to, edge[tot].val = val, edge[tot].next = head[from], head[from] = tot;
}

void dfs_down(int now, int pre) {
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        int val = edge[i].val;
        if (to == pre) {
            if (val == 1)
                one[now].push_back(to), dis1[now]++;
            if (val == 2)
                dis2[now]++;
            continue;
        }
        if (val == 1)
            dis1[now]++, one[now].push_back(to);
        if (val == 2)
            dis2[now]++;
        dfs_down(to, now);
    }
}

void dfs(int now, int pre) {
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        int val = edge[i].val;
        if (to == pre) continue;
        if (val > 2) continue;

    }
}

void solve() {
    n = read();
    for (int i = 2; i <= n; i++) {
        int fa = read(), dis = read();
        add(i, fa, dis), add(fa, i, dis);
    }
    dfs_down(1, -1);
    for (int i = 1; i <= n; i++) {
        ans[i] = 1 + dis2[i];
        ans[i] += dis1[i];
        for (int x : one[i]) {
            ans[i] += dis1[x] - 1;
        }
        printf("%d\n", ans[i]);
    }

}

int main() {
    solve();
    return 0;
}