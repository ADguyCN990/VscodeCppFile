#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 10005
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
int l[MAXN], r[MAXN];
int n, m, k;
void solve() {
    n = read(), m = read(), k = read();
    for (int i = 1; i <= n; i++) {
        l[i] = INF;
        r[i] = -INF;
    }
    for (int i = 1; i <= k; i++) {
        int x = read(), y = read();
        l[x] = min(l[x], y);
        r[x] = max(r[x], y);
    }
    int premx = -INF;
    for (int i = 1; i <= n; i++) {
        if (l[i] == INF) continue;
        if (l[i] < premx) {
            puts("NO");
            return;
        }
        premx = r[i];
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