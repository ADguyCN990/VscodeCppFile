#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define MAXW (1e7+114514)
#define MINW (-1e7+908)

int n;
const int N = 100 + 10;

long double a[N][N];
void solve()
{
    // cin >> s + 1;
    cin >> n;
    string x;
    cin >> x;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 2; i <= n; ++i)
    {

        for (int j = 1; j < i; ++j)
        {
            auto tmp = a[i][j];
            for (int k = 1; k <= n; ++k)
            {
                a[i][k] -= a[j][k] * tmp / a[j][j];

                if (a[i][k] > MAXW)
                {
                    a[i][k] = MAXW;
                }
                if (a[i][k] < MINW)
                {
                    a[i][k] = MINW;
                }
            }
            a[i][j] = 0;
        }
    }
    int total = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i][i] < 0)
        {
            total++;
        }
    }

    // for (int i = 1; i <= n; ++i)
    // {
    //     for (int j = 1; j <= n; ++j)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << (total % 2 == 0 ? "+" : "-") << endl;
}

int main(void)
{
    int t;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
        solve();
    return 0;
}