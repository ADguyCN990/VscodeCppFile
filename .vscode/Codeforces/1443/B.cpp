#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define ll long long
char s[MAXN];

void solve()
{
    ll a, b;
    cin >> a >> b;
    cin >> s + 1;
    int len = strlen(s + 1);
    vector<int> pos;
    for (int i = 1; i <= len; i++)
    {
        if (s[i] == '1')
        {
            pos.emplace_back(i);
        }
    }
    if (pos.empty())
    {
        cout << 0 << endl;
        return;
    }
    ll sum = a;
    for (int i = 0; i < pos.size() - 1; i++)
    {
        if (pos[i + 1] - pos[i] == 1)
            continue;
        sum += min((pos[i + 1] - pos[i] - 1) * b, a);//要么自己引爆，要么由前面的爆炸传过来
    }
    cout << sum << endl;
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