#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 40005
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

int n, m, k;
int a[MAXN], b[MAXN];

int main() {
    n = read(), m = read(), k = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= m; i++) b[i] = read();
    a[n + 1] = 0, b[m + 1] = 0;
    vector<int> row, col;
    int pos;
    for (int i = 1; i <= m + 1; i++) {
        if (b[i] == 1 && b[i - 1] == 0) {
            pos = i;
        }
        if (b[i] == 0 && b[i - 1] == 1) {
           // printf("%d ", i - pos);
            row.push_back(i - pos);
        }
    }
   // puts("");
    for (int i = 1; i <= n + 1; i++) {
        if (a[i] == 1 && a[i - 1] == 0) {
            pos = i;
        }
        if (a[i] == 0 && a[i - 1] == 1) {
            col.push_back(i - pos);
            //printf("%d ", i - pos);
        }
    }
   // puts("");
    ll ans = 0;
    for (int i = 1; i * i <= k; i++) {
        if (k % i) continue;
        ll r = i, c = k / i;
        // 5  3  5 - 3 + 1
        // 4  1  4 - 1 + 1
        ll rowans = 0;
        for (int x : row) rowans += max(0ll, x - r + 1);
        for (int x : col) ans += rowans * max(0ll, x - c + 1);
        if (r != c) {
            ll colans = 0;
            swap(r, c);
            for (int x : col) colans += max(0ll, x - c + 1);
            for (int x : row) ans += colans * max(0ll, x - r + 1);
        }
    }
    printf("%lld\n", ans);
    return 0;
}