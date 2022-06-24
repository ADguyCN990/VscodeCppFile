#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
ll n, k;
ll a[MAXN];



int main() {
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    ll sum = 0;
    for (int i = 1; i <= n; i++) sum += a[i];
    if (sum < k) {
        puts("0");
        return 0;
    }
    cout << sum - (k + 1) / 2;
    return 0;
}