#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#define debug(a) cout << #a << "=" << a << endl;
using namespace std;
const int maxn = 120;
typedef int LL;
LL ans = 0;
char s[maxn][maxn];
struct P
{
    LL shux1, shuy1, shux2, shuy2, shux3, shuy3;
};
LL n, m;
vector<P> v;
void mody4(LL x1, LL y1, LL x2, LL y2, LL x3, LL y3, LL x4, LL y4)
{
    v.push_back({x1, y1, x2, y2, x3, y3});
    v.push_back({x2, y2, x3, y3, x4, y4});
    v.push_back({x1, y1, x2, y2, x4, y4});
    v.push_back({x1, y1, x3, y3, x4, y4});
}
void mody3(LL x1, LL y1, LL x2, LL y2, LL x3, LL y3, LL x4, LL y4)
{
    if (s[x1][y1] == '0')
    {
        v.push_back({x2, y2, x3, y3, x4, y4});
    }
    else if (s[x2][y2] == '0')
    {
        v.push_back({x1, y1, x3, y3, x4, y4});
    }
    else if (s[x3][y3] == '0')
    {
        v.push_back({x1, y1, x2, y2, x4, y4});
    }
    else if (s[x4][y4] == '0')
    {
        v.push_back({x1, y1, x2, y2, x3, y3});
    }
}
void mody2(LL x1, LL y1, LL x2, LL y2, LL x3, LL y3, LL x4, LL y4)
{
    if (s[x1][y1] == '1' && s[x2][y2] == '1')
    {
        v.push_back({x2, y2, x3, y3, x4, y4});
        v.push_back({x1, y1, x3, y3, x4, y4});
    }
    else if (s[x3][y3] == '1' && s[x4][y4] == '1')
    {
        v.push_back({x4, y4, x1, y1, x2, y2});
        v.push_back({x3, y3, x1, y1, x2, y2});
    }
    else if (s[x1][y1] == '1' && s[x3][y3] == '1')
    {
        v.push_back({x3, y3, x2, y2, x4, y4});
        v.push_back({x1, y1, x2, y2, x4, y4});
    }
    else if (s[x2][y2] == '1' && s[x4][y4] == '1')
    {
        v.push_back({x4, y4, x1, y1, x3, y3});
        v.push_back({x2, y2, x1, y1, x3, y3});
    }
    else if (s[x1][y1] == '1' && s[x4][y4] == '1')
    {
        v.push_back({x2, y2, x3, y3, x4, y4});
        v.push_back({x1, y1, x2, y2, x3, y3});
    }
    else if (s[x2][y2] == '1' && s[x3][y3] == '1')
    {
        v.push_back({x1, y1, x3, y3, x4, y4});
        v.push_back({x1, y1, x2, y2, x4, y4});
    }
}
void mody1(LL x1, LL y1, LL x2, LL y2, LL x3, LL y3, LL x4, LL y4)
{
    if (s[x1][y1] == '1')
    {
        v.push_back({x1, y1, x2, y2, x3, y3});
        v.push_back({x3, y3, x1, y1, x4, y4});
        v.push_back({x1, y1, x2, y2, x4, y4});
    }
    else if (s[x2][y2] == '1')
    {
        v.push_back({x2, y2, x1, y1, x4, y4});
        v.push_back({x4, y4, x2, y2, x3, y3});
        v.push_back({x2, y2, x1, y1, x3, y3});
    }
    else if (s[x3][y3] == '1')
    {
        v.push_back({x3, y3, x1, y1, x4, y4});
        v.push_back({x4, y4, x2, y2, x3, y3});
        v.push_back({x1, y1, x2, y2, x3, y3});
    }
    else if (s[x4][y4] == '1')
    {
        v.push_back({x4, y4, x2, y2, x3, y3});
        v.push_back({x3, y3, x1, y1, x4, y4});
        v.push_back({x1, y1, x2, y2, x4, y4});
    }
}
void solve(LL x1, LL y1, LL x2, LL y2, LL x3, LL y3, LL x4, LL y4)
{
    LL sum1 = 0;
    LL sum0 = 0;
    if (s[x1][y1] == '1')
        sum1++;
    else
        sum0++;
    if (s[x2][y2] == '1')
        sum1++;
    else
        sum0++;
    if (s[x3][y3] == '1')
        sum1++;
    else
        sum0++;
    if (s[x4][y4] == '1')
        sum1++;
    else
        sum0++;
    if (sum1 == 4)
    {
        mody4(x1, y1, x2, y2, x3, y3, x4, y4);
        s[x1][y1] = s[x2][y2] = s[x3][y3] = s[x4][y4] = '0';
        ans += 4;
    }
    else if (sum1 == 3)
    {
        mody3(x1, y1, x2, y2, x3, y3, x4, y4);
        s[x1][y1] = s[x2][y2] = s[x3][y3] = s[x4][y4] = '0';
        ans += 1;
    }
    else if (sum1 == 2)
    {
        mody2(x1, y1, x2, y2, x3, y3, x4, y4);
        s[x1][y1] = s[x2][y2] = s[x3][y3] = s[x4][y4] = '0';
        ans += 2;
    }
    else if (sum1 == 1)
    {
        mody1(x1, y1, x2, y2, x3, y3, x4, y4);
        s[x1][y1] = s[x2][y2] = s[x3][y3] = s[x4][y4] = '0';
        ans += 3;
    }
    else if (sum1 == 0)
    {
        s[x1][y1] = s[x2][y2] = s[x3][y3] = s[x4][y4] = '0';
        ans += 0;
    }
}
void presolve()
{
    for (LL i = 1; i <= n - 2; i++)
    {
        for (LL j = 1; j <= m; j++)
        {
            if (j < m)
            {
                if (s[i][j] == '1')
                {
                    s[i][j] = char('0' + (1 ^ (s[i][j] - '0')));
                    s[i + 1][j] = char('0' + (1 ^ (s[i + 1][j] - '0')));
                    s[i][j + 1] = (char)('0' + (1 ^ (s[i][j + 1] - '0')));
                    ans++;
                    v.push_back({i, j, i + 1, j, i, j + 1});
                }
            }
            else
            {
                if (s[i][j] == '1')
                {
                    s[i][j] = char('0' + (1 ^ (s[i][j] - '0')));
                    s[i + 1][j] = char('0' + (1 ^ (s[i + 1][j] - '0')));
                    s[i + 1][j - 1] = char('0' + (1 ^ (s[i + 1][j - 1] - '0')));
                    ans++;
                    v.push_back({i, j, i + 1, j, i + 1, j - 1});
                }
            }
        }
    }
    for (LL j = 1; j <= m - 2; j++)
    {
        if (s[n - 1][j] == '1')
        {
            s[n - 1][j] = '0';
            s[n - 1][j + 1] = char('0' + (1 ^ (s[n - 1][j + 1] - '0')));
            s[n][j + 1] = char('0' + (1 ^ (s[n][j + 1] - '0')));
            ans++;
            v.push_back({n - 1, j, n - 1, j + 1, n, j + 1});
        }
        if (s[n][j] == '1')
        {
            s[n][j] = '0';
            s[n - 1][j + 1] = char('0' + (1 ^ (s[n - 1][j + 1] - '0')));
            s[n][j + 1] = char('0' + (1 ^ (s[n][j + 1] - '0')));
            ans++;
            v.push_back({n, j, n - 1, j + 1, n, j + 1});
        }
    }
    solve(n - 1, m - 1, n - 1, m, n, m - 1, n, m);
}
int main(void)
{
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    LL t;
    cin >> t;
    while (t--)
    {
        v.clear();
        ans = 0;
        cin >> n >> m;
        for (LL i = 1; i <= n; i++)
        {
            for (LL j = 1; j <= m; j++)
            {
                cin >> s[i][j];
            }
        }
        presolve();
        cout << ans << endl;
        for (auto i : v)
        {
            cout << i.shux1 << " " << i.shuy1 << " " << i.shux2 << " " << i.shuy2 << " " << i.shux3 << " " << i.shuy3 << endl;
        }
    }
    return 0;
}