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
void solve() {
    n = read();
    int two = 0, three = 0;
    if (n == 1) {
        puts("0");
        return;
    }
    while (n % 2 == 0) {
        n /= 2;
        two++;
    }
    while (n % 3 == 0) {
        n /= 3;
        three++;
    }
    if (n != 1) {
        puts("-1");
        return;
    }
    if (two <= three && three > 0) {
        printf("%d\n", three - two + three);
    }
    else {
        puts("-1");
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