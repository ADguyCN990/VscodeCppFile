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
    vector<int> a(MAXN + 1), b(MAXN + 1);
    int n;
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read(), b[i] = read();
    for (int i = 2; i <= n; i++) {
        if (a[i] < a[i - 1] || b[i] < b[i - 1]) {
            puts("NO");
            return;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] > a[i]) {
            puts("NO");
            return;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] - b[i - 1] > a[i] - a[i - 1]) {
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