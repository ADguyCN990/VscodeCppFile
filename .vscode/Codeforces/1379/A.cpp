#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define per(i, x, y) for (int i = x; i >= y; i--)
#define pb emplace_back
ll read()
{
    ll x = 0, f = 1;
    char ch;
    do
    {
        ch = getchar();
        if (ch == '-')
            f = -1;
    } while (ch < '0' || ch > '9');
    do
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    } while (ch >= '0' && ch <= '9');
    return x * f;
}
int n;
string s, tmp;
string p = "abacaba";
void solve()
{
    cin >> n >> s;
    int flag = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i + 6 >= n)
            break;
        //几个字符匹配
        int ok = 0;
        for (int j = 0; j < 7; ++j)
        {
            if (s[i + j] == '?' || p[j] == s[i + j])
                ok++;
            else
                break;
        }
        if (ok == 7)
        {
            tmp = s;
            for (int j = 0; j < 7; ++j)
                tmp[i + j] = p[j];

            //出现几次
            int cnt = 0;
            int pos = 0;
            while (1)
            {
                pos = tmp.find(p, pos);
                // printf("pos = %d\n", (int)pos);
                if (pos == tmp.npos)
                    break;
                pos = pos + 3;
                cnt++;
            }
            if (cnt == 1)
            {
                flag = 1;
                cout << "YES" << endl;
                for (int j = 0; j < n; ++j)
                {
                    cout << (tmp[j] == '?' ? 'z' : tmp[j]);
                }
                cout << endl;
                break;
            }
        }
    }
    if (!flag)
        cout << "NO" << endl;
}

int main()
{
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}