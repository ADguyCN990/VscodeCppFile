#include<bits/stdc++.h>
using namespace std;
#define ll long long

int work(int x, int p) {
    int cnt = 0;
    while (x) {
        int u = x % p;
        if (u == 1) cnt++;
        x /= p;
    }
    return cnt;
} 

void solve() {
    int p1, p2, x;
    scanf("%d%d%d", &x, &p1, &p2);
    int a = work(x, p1);
    int b = work(x, p2);
    if (a > b)
        puts(">");
    else if (a < b)
        puts("<");
    else
        puts("=");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}