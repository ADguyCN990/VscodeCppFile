#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
#define MAXM 200005
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f3f3f3f3f
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
struct node {
    ll val;
    int u, v;
}a[MAXM];
ll dis[MAXN];

void solve() {
    n = read(), m = read();
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read();
        ll w = read();
        a[i] = {-w, u, v};
    }
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int i = 1; i <= m; i++) {
            ll val = a[i].val;
            int u = a[i].u;
            int v = a[i].v;
            if (dis[v] > dis[u] + val) {
                dis[v] = dis[u] + val;
            } 
        }
    }
    ll ans = dis[n];
    for (int i = 1; i <= m; i++) {
        ll val = a[i].val;
        int u = a[i].u;
        int v = a[i].v;
        if (dis[v] > dis[u] + val) {
            dis[v] = dis[u] + val;
        }
    }
    if (dis[n] != ans)
        puts("inf");
    else
        printf("%lld\n", -ans);
}

int main() {
    solve();
    return 0;
}