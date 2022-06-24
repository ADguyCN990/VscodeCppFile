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
int n, x;
vector<int> mp[MAXN];
int d[MAXN];
void init() {
    for (int i = 1; i <= n; i++) mp[i].clear(), d[i] = 0;
}

void solve() {
    n = read(), x = read();
    init();
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        mp[u].pb(v), mp[v].pb(u);
        d[u]++, d[v]++;
    }
    if (d[x] == 1) {
        puts("Ayush");
        return;
    }
    if (n == 1) {
        puts("Ayush");
        return;
    }
    if ((n - 2) & 1) {
        puts("Ashish");
    }
    else
        puts("Ayush");
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}