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
    if (n <= 2) {
        puts("0");
        for (int i = 1; i <= n; i++) printf("%lld ", a[i]);
        puts("");
        return;
    }
    int cnt = 0;
    for (int i = 2; i < n; i++) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            cnt++;
            a[i + 1] = max(a[i], a[i + 2]);
        }
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    puts("");
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}