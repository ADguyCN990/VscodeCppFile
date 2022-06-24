#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
#define ll long long
ll n;
char s[MAXN];


void solve() {
    scanf("%lld", &n);
    scanf("%s", s + 1);
    ll k = 0, ans = 0;
    for (int i = n; i >= 1; i--) {
        if (s[i] == '0')
            k++;
        else {
            if (k > 0)
                ans += i, k--;
            else
                k++; 
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }

    return 0;
}