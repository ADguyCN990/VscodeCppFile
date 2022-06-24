#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n;

void solve()
{
    cin >> n;
    int temp;
    for (int i = 1; i <= n; i++)
        cin >> temp;

    for (int i = 1; i <= n; i += 2)
    {
        cout << 2 << ' ' << i << ' ' << i + 1 << endl;
        cout << 1 << ' ' << i << ' ' << i + 1 << endl;
        cout << 1 << ' ' << i << ' ' << i + 1 << endl;
        cout << 2 << ' ' << i << ' ' << i + 1 << endl;
        cout << 1 << ' ' << i << ' ' << i + 1 << endl;
        cout << 1 << ' ' << i << ' ' << i + 1 << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}