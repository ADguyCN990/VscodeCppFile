#include <bits/stdc++.h>
using namespace std;
#define MAXN 105
#define ll long long
ll a[MAXN][MAXN];
int visit[MAXN];
ll n, m;
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
        sort(a[i] + 1, a[i] + 1 + m); //每行都从小到大进行排序
    }
    //排序后每次找到一个最小的，和最后最大的进行交换
    for (int i = m; i >= 1; i--)
    {
        int min_id = 1;
        for (int j = 1; j <= n; j++)
        {
            if (a[j][1] < a[min_id][1])
                min_id = j;
        }
        rotate(a[min_id] + 1, a[min_id] + 2, a[min_id] + i + 1);
        // cout<<"_______"<<m-i+1<<" :"<<endl;
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= m; j++)
        //     {
        //         cout << a[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout<<endl;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
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