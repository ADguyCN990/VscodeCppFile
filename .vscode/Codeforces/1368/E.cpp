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
int n, m;
vector<int> mp[MAXN];
bool vis[MAXN];
void init() {
    for (int i = 1; i <= n; i++) mp[i].clear(), vis[i] = false;
}

void solve() {
    n = read(), m = read();
    init();
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read();
        mp[v].pb(u); //建反图
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue; //如果i这个点还没被删掉
        bool flag = true;
        for (int u : mp[i]) {
            if (vis[u]) continue; //第一条边存在且未被删除
            for (int v : mp[u]) {
                if (vis[v]) continue; //第二条边存在且未被删除
                ans.pb(i);
                vis[i] = true;
                flag = false;
                break;
            }
            if (!flag)
                break;
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
    puts("");
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}