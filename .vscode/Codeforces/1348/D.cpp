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
    vector<ll> ans;
    ll n = read();
    for (ll i = 1; i <= n; i *= 2) {
        ans.pb(i);
        n -= i;
    }   
    if (n)
        ans.pb(n);
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size() - 1);
    for (int i = 1; i < ans.size(); i++)
        printf("%lld ", ans[i] - ans[i - 1]);
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