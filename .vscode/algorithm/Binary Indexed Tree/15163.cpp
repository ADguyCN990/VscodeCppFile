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
vector<int> num;
int a[MAXN];
int c[MAXN];
int n;
int findx(int x) {
    return lower_bound(num.begin(), num.end(), x) - num.begin() + 1;
}
int lowbit(int x) {
    return x & -x;
}

void update(int x, int val) {
    for (int i = x; i <= n; i += lowbit(i))
        c[i] += val;
}

int ask(int x) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i))
        ans += c[i];
    return ans;
}

void solve() {
    n = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        num.pb(a[i]);
    }
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    for (int i = 1; i <= n; i++)
        a[i] = findx(a[i]);
    ll ans = 0;
    int mx = num.size();
    for (int i = 1; i <= n; i++) {
        int u = a[i];
        ans += ask(mx) - ask(u);
        update(a[i], 1);
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}