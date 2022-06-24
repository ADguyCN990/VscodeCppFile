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
    bool flag = true;
    for (int i = 2; i <= n; i++) {
        if (a[i] < a[i - 1]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        puts("0");
        return;
    }
    if (!flag && a[n] < 0) {
        puts("-1");
        return;
    } 
    if (a[n - 1] > a[n]) {
        puts("-1");
        return;
    }
    printf("%d\n", n - 2);
    for (int i = 1; i <= n - 2; i++) {
        printf("%d %d %d\n", i, n - 1, n);
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