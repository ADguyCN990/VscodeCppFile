#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s, t;
map<char, int> mp;
void solve()
{
    getline(cin, s);
    getline(cin, t);
    int now = 1;
    int p = 0;
    for (int i = 1; i < t.length(); i++)
    {
        if (t[i] == t[i - 1])
            now++;
        else
        {
            int pp = 0;
            for (int j = p; j < s.length(); j++)
            {
                if (s[j] == t[j - 1])
                    pp++;
                else
                {
                    p = j;
                    break;
                }
            }
            if (pp = now)
                now = 1;
            else
            {
                if (mp[t[i - 1]] != 1)
                {
                    cout << t[i - 1];
                }
                mp[t[i - 1]] = 1;
                now = 1;
            }
        }       
    }
    if (now != s.length() - p && mp[s[p]] != 1)
            cout << s[p];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}