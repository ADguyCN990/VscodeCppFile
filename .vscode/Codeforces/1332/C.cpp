#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long

int cnt[30];
char s[MAXN];
int n, k;
int num[MAXN][26];

void solve() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 26; j++)
            num[i][j] = 0;
    scanf("%s", s + 1);
    int ans = 0;
    for (int i = 1; i <= (k + 1) / 2; i++) {
        int maxn = 0;
        for (int j = 1; j <= n; j = j + k) {
            num[i][s[j + i - 1] - 'a']++;
            if (k != 2 * i - 1)
                num[i][s[j + k - i] - 'a']++;
            maxn = max(num[i][s[j + i - 1] - 'a'], maxn);
            maxn = max(num[i][s[j + k - i] - 'a'], maxn);
        }
        if (k == 2 * i - 1)
            ans += (n / k) - maxn;
        else
            ans += 2 * (n / k) - maxn;
    }
    printf("%d\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}
