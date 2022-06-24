#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        printf("%d ", (i - 1) % 20 + 1);
    }
    puts("");
    return 0;
}