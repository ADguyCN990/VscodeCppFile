#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ll a = 0, b = 0;
    for (int i = 1; i <= 5; i++) {
        ll tmp ;
        cin >> tmp;
        a += tmp;
    }
    for (int i = 1; i <= 5; i++) {
        ll tmp;
        cin >> tmp;
        b += tmp;
    }
    if (a >= b)
        puts("Blue");
    else
        puts("Red");
    return 0;
}