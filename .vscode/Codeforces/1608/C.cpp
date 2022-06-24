#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f
int n, cnt;
int a[MAXN], b[MAXN];
int flag[MAXN];
int ans[MAXN];

struct node
{
    int id, zhi;
} x[101000], y[101000];

bool cmp(node a, node b)
{
    return a.zhi > b.zhi;
}

void work()
{
    for (int i = 1; i <= n; i++)
    {
        if (flag[x[i].id] == 0)
        {
            cnt++;
        }
        flag[x[i].id]++;
        if (flag[x[i].id] == 0)
        {
            cnt--;
        }

        if (flag[y[i].id] == 0)
        {
            cnt++;
        }
        flag[y[i].id]--;
        if (flag[y[i].id] == 0)
        {
            cnt--;
        }
        ans[y[i].id] = ans[x[i].id] = 1;
        if (cnt == 0)
        {
            break;
        }
    }
}

void solve()
{
    cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans[i] = flag[i] = 0;
        x[i] = node{i, a[i]};
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        y[i] = node{i, b[i]};
    }
    sort(x + 1, x + n + 1, cmp);//降序
    sort(y + 1, y + n + 1, cmp);//降序
    work();
    for (int i = 1; i <= n; i++)
    {
        if (ans[i])
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
    cout << endl;
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