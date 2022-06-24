#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, t;

int main() {
    cin >> n >> t;
    //小的当祖宗
    for (int i = n; i > 1; i--) {
        cout << i << " " << i - 1 << "\n";
    }
    cout << 1 << " " << n << "\n";
    return 0;
}