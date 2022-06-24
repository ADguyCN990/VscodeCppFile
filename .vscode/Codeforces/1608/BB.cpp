#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

const int MAXL = 1 << 22;
char i_str[MAXL], o_str[MAXL], *i_s, *i_t;
int o_t;
#define Flush fwrite(o_str, 1, o_t, stdout), o_t = 0
#define space pc(' ')
#define enter pc('\n')

inline char gc()
{
    if (i_s == i_t)
    {
        i_s = i_str;
        i_t = i_s + fread(i_str, 1, MAXL, stdin);
        return i_s == i_t ? EOF : *i_s++;
    }
    else
        return *i_s++;
}

inline int read()
{
    int x = 0, f = 0;
    char ch = gc();
    for (; ch < '0' || ch > '9'; ch = gc())
        if (ch == '-')
            f = 1;
    for (; ch >= '0' && ch <= '9'; ch = gc())
        x = x * 10 + (ch ^ 48);
    return f ? -x : x;
}

inline void pc(char x)
{
    o_str[o_t++] = x;
    if (o_t == MAXL)
        Flush;
}

void write(int x)
{
    if (x < 0)
        pc('-'), x = -x;
    if (x > 9)
        write(x / 10);
    pc(x % 10 ^ 48);
}

int T;

inline void Solve()
{
    int n = read(), a = read(), b = read();
    for (register int i = 1; i <= n; ++i)
        if (a + b + 2 > n || abs(a - b) > 1)
        {
            write(-1), enter;
            return;
        }
    if (a == b)
    {
        for (register int i = n; i >= a + a + 3; --i)
            write(i), space;
        for (register int i = a + 1; i; --i)
            write(a + a + 3 - i), space, write(i), space;
        enter;
        return;
    }
    vector<int> A, B;
    bool flg = false;
    if (a > b)
        a ^= b ^= a ^= b, flg = true;
    for (register int i = b; i; --i)
        A.push_back(b + b + 1 - i), A.push_back(i);
    for (register int i = b + b + 1; i <= n; ++i)
        B.push_back(i);
    if (flg)
    {
        for (register int i = 0; i < A.size(); ++i)
            write(n - A[i] + 1), space;
        for (register int i = 0; i < B.size(); ++i)
            write(n - B[i] + 1), space;
        enter;
        return;
    }
    for (register int i = 0; i < A.size(); ++i)
        write(A[i]), space;
    for (register int i = 0; i < B.size(); ++i)
        write(B[i]), space;
    enter;
    return;
}

signed main()
{
    T = read();
    while (T--)
        Solve();
    Flush;
    return 0;
}