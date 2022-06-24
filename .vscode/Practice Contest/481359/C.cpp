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
int a[MAXN], c[MAXN], b[MAXN], pos[MAXN];
int n;

int lowbit(int x) {return x & (-x);} 
void add(int x, int k) {
    for (int i = x; i <= n; i += lowbit(i)) c[i] += k;
}
int ask(int x) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i)) ans += c[i];
    return ans;
}

void solve() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read(), pos[a[i]] = i;
    for (int i = 1; i <= n; i++) b[i] = read();
    memset(c, 0, sizeof c);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int idx = pos[b[i]];
        ans += ask(n) - ask(idx);
        add(idx, 1);
    }
    printf("%lld\n", ans);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}