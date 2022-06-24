#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a, ma, b, mb, c, mc;

int main() {
    cin >> ma >> a >> mb >> b >> mc >> c;
    for (int i = 1; i <= 100; i++) {
        if (i % 3 == 1) {
            //a to b
            if (a + b <= mb)
                b = a + b, a = 0;
            else
                a = a - (mb - b), b = mb;
        }
        else if (i % 3 == 2) {
            //b to c
            if (b + c <= mc)
                c = b + c, b = 0;
            else
                b = b - (mc - c), c = mc;
        }
        else {
            //c to a
            if (a + c <= ma)
                a = a + c, c = 0;
            else
                c = c - (ma - a), a = ma;
        }
    }
    printf("%lld\n%lld\n%lld\n", a, b, c);
    return 0;
}