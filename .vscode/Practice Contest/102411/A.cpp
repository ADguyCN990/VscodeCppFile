#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, a, b;

int main() {
    cin >> a >> b >> n;
    ll sa = a, sb = b, cnt = 0;
    bool f = 1;
    while (sa < n || sb < n){
        if (f) sa += (b - a);
        else sb += (b - a);
        cnt++, f ^= 1;
    }
    printf("%lld\n", cnt);
    // n - b b - a
    // n - a b - a
    // printf("%lld\n", min((n - b + b - a - 1) / (b - a), (n - a + b - a - 1) / (b - a)));
    return 0;
}