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
ll n;
ll a[MAXN];
int sum[MAXN];
void solve() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    memset(sum, 0, sizeof sum);
    for (int i = 1; i <= n; i++) 
        sum[i] = sum[i - 1] + (a[i] == 0);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ll len = j - i + 1;
            int sum0 = sum[j] - sum[i - 1];
            ans += sum0 + len;
        }
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