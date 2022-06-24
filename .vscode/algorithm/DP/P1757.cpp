#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
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
ll V, n;
vector<int> g[MAXN];
ll v[MAXN], w[MAXN];
ll dp[MAXN];

void solve() {
    V = read(), n = read();
    for (int i = 1; i <= n; i++) {
        ll fa;
        v[i] = read(), w[i] = read(), fa = read();
        g[fa].pb(i);
    }   
    for (int i = 1; i <= 1000; i++) 
        if (g[i].size()) 
            for (int j = V; j >= 0; j--)
                for (int k = 0; k < g[i].size(); k++)
                    if (j >= v[g[i][k]])
                        dp[j] = max(dp[j - v[g[i][k]]] + w[g[i][k]], dp[j]);
        
    
    printf("%lld\n", dp[V]);
}

int main() {
    solve();
    return 0;
}