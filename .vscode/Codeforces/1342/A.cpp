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
    ll x = read(), y = read(), a = read(), b = read();
    //a是变一个，b是变两个
    if (a * 2 <= b) {
        ll dif = abs(x) + abs(y);
        printf("%lld\n", dif * a);
        return;
    }
    ll same = min(x, y);
    ll ans1 = b * same + (max(x, y) - min(x, y)) * a;
    printf("%lld\n", ans1);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}