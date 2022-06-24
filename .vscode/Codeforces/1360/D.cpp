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
void solve() {
    ll n = read(), k = read();
    if (k >= n) {
        puts("1");
        return;
    }
    if (k == 1) {
        printf("%lld\n", n);
        return;
    }
    vector<ll> v;
    for (ll i = 1; i <= n / i; i++) {
        if (n % i == 0) {
            v.pb(i);
            if (i != n / i) v.pb(n / i);
        }
    }
    sort(v.begin(), v.end());
    int len = v.size();
    ll pos = upper_bound(v.begin(), v.end(), k) - v.begin() - 1;
    printf("%lld\n", n / v[pos]);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }
    
    return 0;
}