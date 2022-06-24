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
    ll a = read(), b = read(), c = read();
    ll aa, bb, cc;
    ll ans = INF;
    for (int i = 1; i <= 30000; i++) {
        for (int j = 1; i * j <= 30000; j++) {
            for (int k = 1; i * j * k <= 30000; k++) {
                ll x = i, y = i * j, z = i * j * k;
                ll dif = abs(a - x) + abs(b - y) + abs(c - z);
                if (dif < ans) {
                    ans = dif;
                    aa = x;
                    bb = y;
                    cc = z;
                }
            }
        }
    }
    printf("%lld\n", ans);
    printf("%lld %lld %lld\n", aa, bb, cc);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}