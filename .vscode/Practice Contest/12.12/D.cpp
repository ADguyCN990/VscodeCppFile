#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int a[N]; //桶
int n, cnt;
int vis[N];

void init()
{
    for (int i = 0; i <= n + 1; ++i)
    {
        vis[i] = 0;
    }
    cnt = 0;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        a[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        a[tmp] = i;
    }
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        init();
        for (int j = i; j <= n; ++j)
        {
            if (vis[a[j]-1] && vis[a[j]+1])
            {
                cnt--;
            }

            if (vis[a[j]-1] == 0 && vis[a[j]+1] == 0)
                cnt++;
            vis[a[j]] = 1;
            if (cnt <= 2)
            {
                ans++;
            }
        }
        // cout << i << "   " << ans << endl;
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}