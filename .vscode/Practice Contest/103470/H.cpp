#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
const int N = 1e5 + 5;
ll a[N], f[N][2];
int t[N];
vector<int> ve[N];

void init(){
    for (int i=0;i<=n;++i){
        ve[i].clear();
        f[i][0] = f[i][1] = 0;
    }
}

void dfs(int cur, int pre){
    if (ve[cur].size() <= 1){
        f[cur][0] = a[cur];
        f[cur][1] = 0;
        return ;
    }
    ll mx1 = -1, mx31 = -1, mx32 = -1, id1 = -1, id31 = -1, id32 = -1;
    for (auto i : ve[cur]){
        f[cur][1] += a[i];
        if (a[i] >= mx1){
            mx1 = a[i], id1 = i;
        }
        
    }
    ll x1, x2 = 0;
    f[cur][0] = a[cur];
    for (auto i : ve[cur]){
        if (i == pre) continue;
        dfs(i, cur);
        f[cur][0] += f[i][0] - a[i];
        if (i != id1){
            if (t[i] == 3)
                x2 = max(x2, a[i] - f[i][1]);
        }
    }

    f[cur][0] = mx1 + f[cur][0];
    // if (t[id1] == 3 && id32 > 0){
    //     x2 = max(x1 + mx32 - f[id32][0], x1 + mx32 - f[id1][0]);
    // }
    // else if (id31 > 0){
    //     x2 = max(x1 + mx31 - f[id31][0], x1 + mx31 - f[id1][0]);
    // }
}

void solve(){
    scanf("%d", &n);
    init();
    int u, v;
    for (int i=1;i<=n;++i){
        scanf("%lld", &a[i]);
    }
    for (int i=1;i<=n;++i){
        scanf("%d", &t[i]);
    }
    for (int i=1;i<n;++i){
        scanf("%d%d", &u, &v);
        ve[u].push_back(v), ve[v].push_back(u);
    }
    dfs(1, 0);
    printf("%lld\n", max({f[1][0], f[1][1]}));
}

int main(void){
    int T;
    scanf("%d", &T);
    while (T--){
        solve();
    }
    return 0;
}