#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
ll read()
{
    ll x = 0, f = 1;
    char ch;
    do
    {
        ch = getchar();
        if (ch == '-')
            f = -1;
    } while (ch < '0' || ch > '9');
    do
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    } while (ch >= '0' && ch <= '9');
    return x * f;
}
int a[MAXN];
int b[MAXN];
int n;
void solve() {
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    a[n + 1] = a[1];
    b[1] = 1;
    int mx = 1, flag = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] != a[i - 1]) {
            if (b[i - 1] != 1)
                b[i] = b[i - 1] - 1;
            else
                b[i] = b[i - 1] + 1;
        }
        else
            b[i] = b[i - 1];
        if (i == n) {
            if (b[i] == 1 && a[i] != a[i + 1]) {
                b[i] = b[i - 1] + 1;
                flag = 1;
            }
        }
        if (b[i] > mx)
            mx = b[i];
    }
    if (flag) {
        mx = 1;
        int f = 0;
        for (int i = 2; i <= n; i++) {
            if (b[i] == b[i - 1] && !f) {
                if (b[i] == 1)
                    b[i]++;
                else
                    b[i]--;
                f = 1;
                continue;
            }
            if (f) {
                if (a[i] != a[i - 1]) {
                    if (b[i - 1] != 1)
                        b[i] = b[i - 1] - 1;
                    else
                        b[i] = b[i - 1] + 1;
                }
                else
                    b[i] = b[i - 1];
                if (i == n)
                    if (b[i] == 1 && a[i] != a[i + 1])
                        b[i] = b[i - 1] + 1;
            }
            if (b[i] > mx)
                mx = b[i];
        }
    }
    printf("%d\n", mx);
    for (int i = 1; i <= n; i++) printf("%d ", b[i]);
    puts("");
}

int main() {
    int t;
    t = read();
    while (t--) {
        solve();
    }
    return 0;
}