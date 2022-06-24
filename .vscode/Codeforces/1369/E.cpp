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
ll n, m;
ll a[MAXN];
struct node {
    int x, y;
}b[MAXN];
vector<int> pos[MAXN];
vector<int> ans;
bool vis[MAXN];
void solve() {
    n = read(), m = read();
    memset(vis, false, sizeof vis);
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= m; i++) {
        b[i].x = read(), b[i].y = read();
    }
    for (int i = 1; i <= m; i++) {
        int u = b[i].x, v = b[i].y;
        a[u]--, a[v]--;
        pos[u].pb(i), pos[v].pb(i);
    }
    queue<int> q; //队列中存放的是商品编号
    for (int i = 1; i <= n; i++) 
        if (a[i] >= 0) //有富足
            q.push(i);
    while (q.size()) {
        int now = q.front(); //当前不存在供不应求的商品的编号
        q.pop();
        for (int x : pos[now]) {
            //x表示对now这个商品有需求的顾客
            if (!vis[x]) {
                vis[x] = true;
                ans.pb(x);
            }
            //x这个顾客买这个保证卖不完的商品即可，另一种商品的需求就减少了
            int to;
            if (b[x].x == now)
                to = b[x].y;
            else
                to = b[x].x;
            a[to]++;
            if (a[to] == 0)
                q.push(to);
        }
    }
    //若有解输出拓扑序的逆序即可
    if (ans.size() < m) {
        puts("DEAD");
        return;
    }
    puts("ALIVE");
    reverse(ans.begin(), ans.end());
    for (int x : ans) printf("%d ", x);
}

int main() {
    solve();
    return 0;
}