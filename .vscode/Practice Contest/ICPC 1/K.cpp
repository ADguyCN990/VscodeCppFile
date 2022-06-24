#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
const int N = 100 + 10;
struct node{
    int v;int son;
    friend bool  operator < (node x, node y){
        return x.son < y.son;
    }
};
vector<node> ve[N];
int val[N];

int dfs1(int cur, int pre){
    if (ve[cur].size()==1){
        return 1;
    }
    int vlen = ve[cur].size(), sums = 0;
    for (auto & i : ve[cur]){
        if (i.v == pre) continue;
        i.son = dfs1(i.v, cur);
        sums += i.son;
    }
    sort(ve[cur].begin(), ve[cur].end());
    return sums;
}

void dfs2(int cur, int pre, int & dep){
    int vlen = ve[cur].size();
    for (int i=0;i<vlen;++i){
        if (pre == ve[cur][i].v) continue;
        dep++;
        val[ve[cur][i].v] = dep;
        dfs2(ve[cur][i].v, cur, dep);
        dep ++;
    }
}

void init(){
    for (int i=0;i<=n;++i){
        ve[i].clear();
        val[i] = 0;
    }
}

void solve(){
    init();
    cin >> n;
    int a, b;
    for (int i=1;i<n;++i){
        cin >> a >> b;
        ve[a].push_back(node{b, 0}), ve[b].push_back(node{a, 0});
    }
    dfs1(1, 0);
    int dep = 0;
    dfs2(1, 0, dep);
    ll ans = 0;
    for (int i=1;i<=n;++i){
        ans += val[i];
    }
    // for (int i=0;i<=n;++i){
    //     printf(i==n?"%d\n":"%d ", val[i]);
    // }
    double res = 1.0*ans/(n-1);
    
    cout << fixed<<setprecision(9)<<res << endl;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}