#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll x, y, n;

void solve(){
    scanf("%lld%lld%lld", &x, &y, &n);
    ll res = n / (x + y);
    ll p1 = ceil(1.0 * n / (x + y)) * x * 3;
    ll p2 = n / (x + y) * x * 3;
    ll rem = n - n / (x + y) * (x + y);
    p2 += rem * 3;
    printf("%lld\n", min(p1, p2));
}

int main(void){
    int t;
    scanf("%d", &t);
    while (t--){
        solve();
    }

    return 0;
}