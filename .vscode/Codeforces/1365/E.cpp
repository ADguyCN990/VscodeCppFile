#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 505
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
int n;
ll a[MAXN];
void solve() {
    n = read();
    ll ans = 0;
    for (int i = 1; i <= n; i++) a[i] = read();
    if (n == 1) {
        printf("%lld\n", a[1]);
        return;
    }
    if (n == 2) {
        printf("%lld\n", a[1] | a[2]);
        return;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                ans = max(ans, a[i] | a[j] | a[k]);
            }
        }
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}