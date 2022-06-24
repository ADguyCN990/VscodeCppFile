#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 405
int d[MAXN];
int n;
int t[4][MAXN];
struct node
{
    int l, r;
} s[4][405][405];
vector<int> ab[405];
vector<int> ac[405];
vector<int> bc[405];
map<pair<int, int>, int> mp;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    for (int j = 1; j <= 3; j++)
        for (int i = 1; i <= n; i++)
            cin >> t[j][i];

    for (int person = 1; person <= 3; person++)
    {
        for (int i = 1; i <= n; i++)
        {
            int now = 1;
            int cnt = 0;
            for (int j = i; j <= n; j++)
            {
                s[person][i][j] = node{now, now + t[person][j] - 1};
                now = now + t[person][j] - 1;
                now = now + d[j] + 1;
            }
            for (int j = 1; j < i; j++)
            {
                s[person][i][j] = node{now, now + t[person][j] - 1};
                now = now + t[person][j] - 1;
                now = now + d[j] + 1;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int kk = 1;
            for (int k = 1; k <= n; k++)
            {
                if (!(s[1][i][k].l > s[2][j][k].r || s[2][j][k].l > s[1][i][k].r))
                {
                    kk = 0;
                }
            }
            if (kk)
                ab[i].emplace_back(j);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int kk = 1;
            for (int k = 1; k <= n; k++)
            {
                if (!(s[1][i][k].l > s[3][j][k].r || s[3][j][k].l > s[1][i][k].r))
                {
                    kk = 0;
                }
            }
            if (kk)
                ac[i].emplace_back(j);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int kk = 1;
            for (int k = 1; k <= n; k++)
            {
                if (!(s[2][i][k].l > s[3][j][k].r || s[3][j][k].l > s[2][i][k].r))
                {
                    kk = 0;
                }
            }
            if (kk)
                bc[i].emplace_back(j);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (auto x : bc[i])
        {
            mp[{i, x}] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (auto x : ab[i])
        {
            for (auto y : ac[i])
            {
                if (mp[{x, y}])
                {
                    cout << i << " " << x << " " << y << endl;
                    return;
                }
            }
        }
    }
    cout << "impossible";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}