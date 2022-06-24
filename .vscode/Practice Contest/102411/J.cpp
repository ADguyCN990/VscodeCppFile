#include<bits/stdc++.h>
using namespace std;
#define MAXN 505
int n;
int a[MAXN][MAXN];
int st[MAXN][MAXN];
char s[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= n; j++) {
            a[i][j] = s[j] - '0';
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int sum = 0;
            for (int k = i + 1; k <= j - 1; k++)
                if (st[i][k])
                    sum += a[k][j];
            if (sum % 10 != a[i][j]) {
                st[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            printf("%d", st[i][j]);
        puts("");
    }
    return 0;
}