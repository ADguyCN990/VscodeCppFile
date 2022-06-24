#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, c, b;
const int Max_n = 5e5 + 10;
int a[Max_n];
int z[Max_n];

void solve()
{
    cin >> n >> c >> b;
    for (int i = 1; i <= b; ++i)
    {
        cin >> z[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        a[i] = -1;
    }
    a[n] = 0;
    int pos = 2;
    if (c & 1)
    {
        c--;
        a[1] = 1;
        a[2] = 0;
        pos++;
    }
    for (int i = 1; i <= b; ++i)
    {
        a[z[i]] = 0;
    }
    int cnt = 0;
    for (int i = pos; i <= n; ++i)
    {
        if (cnt >= c)
        {
            break;
        }
        if (a[i] == -1 && (a[i - 1] == 0 || a[i - 1] == -1))
        {
            a[i] = 1;
            a[i + 1] = 0;
            cnt += 2;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == -1)
        {
            a[i] = 0;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        printf(i == n ? "%d\n" : "%d", a[i]);
    }
}

int main(void)
{
    //	int t;
    //	cin >> t;
    //	while (t--){
    solve();
    //	}
    return 0;
}
