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
char a[MAXN], b[MAXN];
int n;

bool checkEqual(char a[], char b[])
{
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

bool check0(char a[], char b[])
{
    for (int i = 1; i <= n; i++)
        if (a[i] == '1')
            return false;
    return true;
}

void solve()
{
    n = read();
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    bool ok = checkEqual(a, b);
    if (ok)
    {
        puts("0");
        return;
    }
    ok = check0(a, b);
    if (ok)
    {
        puts("-1");
        return;
    }
    int same0 = 0, same1 = 0, dif0 = 0, dif1 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == b[i] && a[i] == '0')
            same0 ++;
        else if (a[i] == b[i] && a[i] == '1')
            same1 ++;
        else if (a[i] == '0')
            dif0 ++;
        else if (a[i] == '1')
            dif1 ++;
    }
    int dif = dif1 + dif0;
    int same = same0 + same1;
    int ans_same = INF;
    int ans_dif = INF;
    if (same % 2 == 1 && same1 - same0 == 1)
        ans_same = same;
    if (dif % 2 ==0 && dif1 == dif0)
        ans_dif = dif; 
    
    int ans = min(ans_same, ans_dif);
    if (ans == INF)
        puts("-1");
    else
        printf("%d\n", ans);
}

int main()
{
    int T;
    T = read();
    while (T--)
    {
        solve();
    }

    return 0;
}