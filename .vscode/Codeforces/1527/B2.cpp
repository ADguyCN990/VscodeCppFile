#include <bits/stdc++.h>
using namespace std;
#define MAXN 1005
#define ll long long
ll n;
string s;
//把0变成1 花一块
//把一个非回文串倒置 花零块
int cnt = 0;
bool check()
{
    int f = 1;
    for (int i = 0, j = s.length() - 1; i <= j; i++, j--)
    {
        if (s[i] != s[j])
        {
            f = 0;
            cnt++;
        }
    }
    return f;
}

void solve()
{
    cin >> n;
    cin >> s;
    cnt = 0;
    int cnt_ = 0;
    //cnt表示不匹配的个数，cnt_表示字符串为0的个数
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '0')
            cnt_++;
    if (check() == true)
    {
        if (cnt_ == 1)
            cout << "BOB" << endl;
        else if (cnt_ % 2 == 1)
            cout << "ALICE" << endl;
        else
            cout << "BOB" << endl;
        return;
    }
    if (cnt == 1&&cnt_==2)
        cout << "DRAW" << endl;
    else
        cout << "ALICE" << endl;
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