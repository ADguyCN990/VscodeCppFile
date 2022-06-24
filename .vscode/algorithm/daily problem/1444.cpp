#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, k, now, len;
    cin >> n >> k;
    string s;
    now = 0;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        len = s.length();
        if (now + len > k) {
            cout << "\n" << s << " ";
            now = len;
        }
        else {
            now += len;
            cout << s << " ";
        }
    }
    return 0;
}