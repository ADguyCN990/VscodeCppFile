#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005

bool check(int l,int r, string s) {
    while (s[l] == s[r] && l < r)
        l++, r--;
    return l >= r;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    if (n == 1)
        cout << s << "\n";
    else {
        int i, j;
        for (i = 0, j = n - 1; i < n;) {
            if (s[i] == s[j])
                i++, j--;
            else
                break;
        }
        if (i <= j) {
            int l = i, r = j;
            for (i = l; i <= r; i++) {
                if (check(i, r, s))
                    break;
            }
            for (j = r; j >= l; j--) {
                if (check(l, j, s))
                    break;
            }
            cout << s.substr(0, l);
            if (r - i > j - l)
                cout << s.substr(i, r - i + 1);
            else
                cout << s.substr(l, j - l + 1);
            cout << s.substr(r + 1, n - 1) << endl;
        }
        else
            cout << s << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}