#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
    ll a[5];    
    cin >> a[1] >> a[2] >> a[3];
    sort(a + 1, a + 4);
    if (a[3] < 1) {
        puts("0");
        return;
    }
    if (a[1] == 0) {
        if (a[2] == 0 && a[3] > 0) {
            puts("1");
            return;
        }
        if (a[2] > 0 && a[3] > 0) {
            if (a[2] == 1 && a[3] == 1) {
                puts("2");
            }
            else if (a[2] > 1 && a[3] > 1) {
                puts("3");
            }
            else {
                puts("2");
            }
            return;
        }
    }
    else if (a[1] == 1) {
        if (a[2] == 1 && a[3] == 1)
            puts("3");
        else if (a[2] > 1 && a[3] > 1)
            puts("4");
        else
            puts("3");
    }
    else if (a[1] == 2) {
        if (a[2] == 2 && a[3] == 2)
            puts("4");
        else if (a[2] >= 2 && a[3] >= 3)
            puts("5");
    }
    else if (a[1] == 3){
        puts("6");
    }
    else {
        puts("7");
    }
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}