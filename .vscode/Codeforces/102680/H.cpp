#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f3f3f3f3f
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define per(i, x, y) for(int i = x; i >= y; i--)
#define pb emplace_back
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
ll base[MAXN];

ll high(ll x) {
    for (int i = 100; i >= 0; i--) {
        int u = x >> i & 1;
        if (u) return 1ll << i;
    }
    return 0;
}

void solve() {
    ll n = read();
    ll cnt = 0;
    ll tmp = n - 1;
    n--;
    //0Red1BLUE
    while (n > 1) {
        cnt++;
        n -= high(n);
    }
    if ((n + cnt) & 1)
        puts("Blue");
    else
        puts("Red");
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}