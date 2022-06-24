#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 500005
#define MAXM 1000005
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
struct node {
    int pos;
    int val;
    friend bool operator < (node a, node b) {
        return a.val < b.val;
    } 
}a[MAXN];
int aa[MAXN];
vector <int> mp[MAXN];
void solve() {
    n = read(), m = read();
    vector<int> ans;
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read();
        mp[u].pb(v), mp[v].pb(u);
    }
    for (int i = 1; i <= n; i++) {
        a[i].val = read();
        a[i].pos = i;
        aa[i] = a[i].val;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        int now = a[i].pos;
        int val = a[i].val;
        unordered_map<int, int> vis;
        for (int to : mp[now]) {
            if (aa[to] == val) {
                puts("-1");
                return;
            }
            vis[aa[to]] = 1;
        }
        for (int j = 1; j < val; j++) {
            if (!vis.count(j)) {
                puts("-1");
                return;
            }
        }
        ans.pb(now);
    }
    for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
}

int main() {
    solve();
    return 0;
}