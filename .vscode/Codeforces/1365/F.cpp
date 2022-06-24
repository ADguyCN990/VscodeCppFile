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
int a[MAXN], b[MAXN];
int n;
void solve() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int j = 1; j <= n; j++) b[j] = read();
    if (n & 1 && a[(n + 1) / 2] != b[(n + 1) / 2]) {
        puts("NO");
        return;
    }
    vector<pii> pa, bb;
    for (int i = 1, j = n; i < j; i++, j--) {
        if (a[i] > a[j])
            pa.pb(a[j], a[i]);
        else
            pa.pb(a[i], a[j]);
    }
    for (int i = 1, j = n; i < j; i++, j--) {
        if (b[i] > b[j])
            bb.pb(b[j], b[i]);
        else
            bb.pb(b[i], b[j]);
    }
    sort(bb.begin(), bb.end());
    sort(pa.begin(), pa.end());
    for (int i = 0; i < pa.size(); i++) {
        pii u = pa[i];
        pii v = bb[i];
        if (u != v) {
            puts("NO");
            return;
        }
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