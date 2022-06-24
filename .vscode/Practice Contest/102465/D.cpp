#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define INF 0x3f3f3f3f
int read() {
    int x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

struct node {
    int mn, mx;
}a[MAXN];
int b[MAXN << 1], idx = 0;
int n, m;

int main() {
    n = read(), m = read();
    for (int i = 0; i <= n; i++) {
        a[i].mn = INF;
        a[i].mx = -INF;
    }
    int t = read();
    int mx = 0;
    while (t--) {
        int x = read(), y = read();
        if (y < a[x].mn)
            a[x].mn = y;
        if (y > a[x].mx)
            a[x].mx = y;
    }
    for (int i = 0; i <= n; i++) {
        if (a[i].mn != INF && a[i].mx != -INF) {
            b[++idx] = a[i].mn;
            b[++idx] = a[i].mx;
        }
    }
    sort(b + 1, b + 1 + idx);
    int mid = b[idx / 2];
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        if (a[i].mn != INF && a[i].mx != -INF) {
            ans += (a[i].mx - a[i].mn) + abs(mid - a[i].mn) + abs(mid - a[i].mx);
        }
    }
    printf("%lld\n", ans + n - 1);
    return 0;
}