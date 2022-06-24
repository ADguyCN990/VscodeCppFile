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
int head[MAXN];int tot;
struct EDGE {
    int to, next, val;
}edge[MAXM];
void add_edge(int from,int to,int val) {
    edge[++tot].to = to; edge[tot].val = val; edge[tot].next = head[from]; head[from] = tot;
}
ll ans1 = -INF, ans2 = -INF, ans;
ll n;

ll dfs(int now, int pre) {
    ll mx = 0;
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        int val = edge[i].val;
        if (to == pre) continue;
        ll tmp = val + dfs(to, now);
        mx = max(mx, tmp);
        
        if (tmp > ans1) {
            ans2 = ans1;
            ans1 = tmp;
        }
        else if (tmp <= ans1 && tmp > ans2) {
            ans2 = tmp;
        }
        ans = max(ans, ans1 + ans2);
    }
    return mx;
}

void solve() {
    n = read();
    for (int i = 1; i < n ; i++) {
        ll u = read(), v = read(), w = read();
        add_edge(u, v, w);
        add_edge(v, u ,w);
    }
    dfs(1, -1);
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}