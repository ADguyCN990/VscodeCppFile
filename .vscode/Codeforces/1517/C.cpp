#include <bits/stdc++.h>
using namespace std;
#define MAXN 505
#define ll long long
ll n;
ll a[MAXN]; //对角线上的元素
ll ans[MAXN][MAXN];
int now_x;
int now_y;
bool ok(int x, int y)
{
    if (x >= 1 && x <= n && y >= 1 && y <= n)
        return 1;
    return 0;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        ans[i][i] = a[i];

    for (int k = 1; k <= n; k++)
    {
        int cnt = ans[k][k] - 1;
        int val = ans[k][k];
        if (k == 1)
        {
            now_x = 2;
            now_y = 1;
        }
        else
        {
            if(ans[k][k-1])
            {
                now_x = k+1;
                now_y = k;
            }
            else
            {
                now_x=k;
                now_y=k-1;
            }
        }
        while (cnt > 0)
        {
            if (ans[now_x][now_y] == 0)//染色
            {
                ans[now_x][now_y] = val;
                cnt--;
            }

            if (ans[now_x][now_y - 1] == 0 && now_y > 1)
            {
                now_y--;
            }
            else if ((ans[now_x][now_y - 1] != 0 || now_y == 1) && now_x != n)
            {
                now_x++;
            }
            else if ((ans[now_x + 1][now_y] != 0 || now_x == n) && (ans[now_x][now_y - 1] != 0 || now_y == 1))
            {
                now_y++;
            }
        }
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= i; j++)
        //     {
        //         cout << ans[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout<<endl;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //int T;
    //cin>>T;
    //while(T--)
    //{
    solve();
    //}
    return 0;
}