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

void solve() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    ll mx = -INF;
    ll dif = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= mx) {
            mx = a[i];
            continue;
        }
        else {
            dif = max(dif, mx - a[i]);
        }
    }
    if (dif == 0) {
        puts("0");
        return;
    }
    int ans = 0;
    for (int i = 60; i >= 0; i--) {
        int u = dif >> i & 1;
        if (u) {
            printf("%d\n", i + 1);
            return;
        }
    }
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}