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
ll a, b;
void solve() {
    a = read(), b = read();
    if (a < b) swap(a, b);
    if (a % b) {
        puts("-1");
        return;
    }
    if (a == b) {
        puts("0");
        return;
    }
    ll num = a / b;
    int cnt = 0;
    while (num % 2 == 0) {
        cnt++;
        num /= 2;
    }
    if (num != 1) {
        puts("-1");
        return;
    }
    printf("%d\n", cnt / 3 + (cnt % 3 + 1) / 2);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}