#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define MAXM 400005

int n,m;
const int N = 1e5 + 10;
int a[N], rt[N], u[N], v[N], w[N];

void init(){
    for (int i=0;i<=n;++i){
        rt[i] = i;
    }
}

int findx(int x){
    if (x==rt[x]) return x;
    rt[x] = findx(rt[x]);
    return rt[x];
}

void merge(int x, int y){
    int fx = findx(x), fy = findx(y);
    if (fx == fy) return;
    rt[fy] = fx;
}

void solve(){
    cin >> n >> m;
    init();
    for (int i=1;i<=m;++i){
        cin >> u[i] >> v[i] >> w[i];
        merge(u[i], v[i]);
    }
    
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}