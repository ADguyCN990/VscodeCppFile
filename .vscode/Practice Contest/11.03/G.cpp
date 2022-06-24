#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m;

int main(void){
    int t;
    scanf("%d", &t);
    while (t--){
        scanf("%lld%lld", &n, &m);
        ll sn = sqrt(n), sm = sqrt(m);
        printf("%lld\n", sn*sm);
    }
    return 0;
}