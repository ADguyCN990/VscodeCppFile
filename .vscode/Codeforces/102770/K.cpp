#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 505
int n, m;
int a[MAXN], b[MAXN];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++) {
        if (a[i] * 3 < b[i]) {
            printf("%d\n", i);
            return;
        }
    }
    puts("-1");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}