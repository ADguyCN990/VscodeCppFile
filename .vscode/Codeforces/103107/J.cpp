#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 500005
#define MAXM 1000005

int n, m;
int a[MAXN], b[MAXN];

int main() {
    scanf("%d%d", &n, &m);
    int x = n, y = n;
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u]++, b[v]++;
        if (a[u] == n) x--;
        if (b[v] == n) y--;
    }
    printf("%d\n", min(x, y));
    return 0;
}