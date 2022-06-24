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
    vector<int> odd, even;
    for (int i = 1; i <= n; i++) {
        if (a[i] & 1)
            odd.pb(a[i]);
        else
            even.pb(a[i]);
    }
    vector<int> o, e;
    o = odd, e = even;
    sort(o.begin(), o.end());
    sort(e.begin(), e.end());
    if (o == odd && e == even) {
        puts("YES");
    }
    else {
        puts("NO");
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