#include <bits/stdc++.h>
using namespace std;
#define ll long long

char k[200], b[200];
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> k + 1 >> b + 1;
    string s(200, '1');
    int cnt = 0;
    for (int i = m - n + 1; i <= m; ++i)
    {
        cnt++;
        s[i] = k[cnt];
    }
    for (int i = m; i >= n; --i)
    {
        s[i - n] = ((b[i] - s[i] + 26) % 26) + 'a';
    }
    string sub = s.substr(1, m);
    cout << sub << endl;
    return 0;
}
