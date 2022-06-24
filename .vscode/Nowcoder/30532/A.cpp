#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005

int n;
int a[MAXN];
int b[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a + 1, a + 1 + n);
    bool flag = true;
    if (a[n] == a[n - 1]) {
        flag = false;
    }
    for (int i = 1; i <= n; i++) {
        if (flag && b[i] == a[n]) {
            printf("%d", b[i] + a[n - 1]);
        }
        else {
            printf("%d ", b[i] + a[n]);
        }
    }
}