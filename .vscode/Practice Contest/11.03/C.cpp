#include <bits/stdc++.h>
using namespace std;

int slen, tlen;
const int Max_s = 5000 + 10, Max_t = 1000 + 10;
const int MOD = 1e9 + 7;
char s[Max_s], t[Max_t];
int f[Max_s][Max_t];

void solve()
{
    cin >> s + 1;
    cin >> t + 1;
    slen = strlen(s + 1), tlen = strlen(t + 1);
    for (int i = 0; i <= slen; i++)
        f[i][0] = 1;
    for (int i = 1; i <= slen; ++i)
    {
        for (int j = 1; j <= tlen; ++j)
        {
            f[i][j] = (f[i][j] + f[i - 1][j]) % MOD;
            if (s[i] == t[j])           
                f[i][j] = (f[i][j] + f[i - 1][j - 1]) % MOD;          
        }
    }
    cout << f[slen][tlen] % MOD << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();

    return 0;
}