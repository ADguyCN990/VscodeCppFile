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
        int a, b, d;
        a = read(), b = read(), d = read();
        double r = d / 2.0;
        double r1 = (d / sqrt(2.0)) / 2.0;
        double sum = 2 * 3.14 * ((d / sqrt(2.0)) / 2.0) * ((d / sqrt(2.0)) / 2.0);
        double ans = sum - (3.14 * r * r) + (d / sqrt(2.0)) * (d / sqrt(2.0));
        printf("%lf\n", ans);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}