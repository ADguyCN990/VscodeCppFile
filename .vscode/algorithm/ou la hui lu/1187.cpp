#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
int f[MAXN];
int din[MAXN], dout[MAXN];
int st[MAXN];
int n;
int find(int x)
{
    if (x == f[x])
        return x;
    else
        return f[x] = find(f[x]);
}
int g[50][50];

void solve()
{
    int n;
    cin >> n;
    memset(st, 0, sizeof st);
    memset(din, 0, sizeof din);
    memset(dout, 0, sizeof dout);
    for (int i = 0; i <= n; i++)
    {
        f[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        int a = s[0] - 'a', b = s[(int)s.size() - 1] - 'a';
        st[a] = st[b] = 1;
        g[a][b]++;
        dout[a]++, din[b]++;
        int pa = find(a), pb = find(b);
        f[pa] = pb;
    }
    int tmp = -1;
    int res = 0;
    for (int i = 0; i < 26; i++) //图的连通性
    {
        if (st[i])
        {
            if (tmp == -1)
                tmp = find(i);
            else
            {
                if (tmp != find(i))
                {
                    res = 1;
                    break;
                }
            }
        }
    }
    int start = 0, ed = 0;
    for (int i = 0; i < 26; i++) //判断有向图入度出度的合法性
    {
        if (din[i] != dout[i])
        {
            if (dout[i] == din[i] + 1)
                start++;
            else if (din[i] - 1 == dout[i])
                ed++;
            else
            {
                res = 1;
                break;
            }
        }
    }
    if (start != 0 || ed != 0)
    {
        if (start != 1 || ed != 1)
            res = 1;
    }
    if (res == 1)
    {
        cout << "The door cannot be opened." << endl;
    }
    else
    {
        cout << "Ordering is possible." << endl;
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
}