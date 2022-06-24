#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
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
bool isfa[MAXN];
vector<int> g[MAXN];
ll V, n;
ll w[MAXN], v[MAXN];
ll dp[32005];

void init() {
    for (int i = 1; i <= n; i++) g[i].clear(), isfa[i] = false;
}

void work(int now, ll j) {
    int len = g[now].size();
    
    for (int st = 0; st < (1 << len); st++) {
        ll sumv = v[now];
        ll sumw = w[now];
        for (int i = 0; i < len; i++) {
            if (st >> i & 1) {
                sumv += v[g[now][i]];
                sumw += w[g[now][i]];
            }
        }
        if (sumv <= j)
            dp[j] = max(dp[j], dp[j - sumv] + sumw);
    }
}

void solve() {
    V = read(), n = read();
    init();
    for (int i = 1; i <= n; i++) {
        v[i] = read();
        w[i] = read();
        w[i] *= v[i];
        int fa = read();
        if (!fa) 
            isfa[i] = true;      
        else 
            g[fa].pb(i);
    }
    for (int i = 1; i <= n; i++)
        if (isfa[i])
            for (int j = V; j >= v[i]; j--)
                work(i, j);
    printf("%lld\n", dp[V]);
}

int main() {
    solve();
    return 0;
}