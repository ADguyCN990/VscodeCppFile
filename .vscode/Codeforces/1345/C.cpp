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
ll n;
ll a[MAXN];
int vis[MAXN];

int mod(int k) {
    if (a[k] < 0)
        return n + a[k] % n;
    else
        return a[k] % n;
}

void solve() {
    n = read();
    for (int i = 0; i < n; i++) a[i] = read();
    for (int i = 0; i < n; i++) vis[i] = false;
    for (int i = 0; i < n; i++) {
        int u = (i + mod(i)) % n;
        if (vis[u]) {
            puts("NO");
            return;
        }
        vis[u] = true;
    }
    puts("YES");
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}