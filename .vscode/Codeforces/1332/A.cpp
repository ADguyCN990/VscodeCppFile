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
    int x, x1, x2, y, y1, y2, a, b, c, d;
    a = read(), b = read(), c = read(), d = read();
    x = read(), y = read(), x1 = read(), y1 = read(), x2 = read(), y2 = read();
    int n = b - a;
    int m = d - c;
    if (x2 == x1 && (a >= 1 || b >= 1) || y1 == y2 && (c >= 1 || d >= 1)) {
        puts("NO");
        return;
    } 
    x += n, y += m;
    if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {
        puts("YES");
        return;
    }
    puts("NO");
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}