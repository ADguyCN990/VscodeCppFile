#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 5005
int n, m;
int ans[MAXN];

int main() {
    cin >> n >> m;
    ll now = 0;
    int pos;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx += (i - 1) / 2;
    }
    if (m > mx) {
        puts("-1");
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        ans[i] = i;
        now += (i - 1) / 2;
        if (now >= m) {
            pos = i;
            break;
        }
    }

    ll del = now - m;
    ans[pos] += del * 2;
    int dx = ans[pos] + 1;
    
    int left = n - pos;
    if (left) {
        ans[n] = 1e9;
        for (int i = n - 1; i >= pos + 1; i--) {
            ans[i] = ans[i + 1] - dx;
        }
    }

    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    puts("");
    return 0;
}