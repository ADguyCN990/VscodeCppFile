#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, p;
const int N = 2e3 + 10;
vector<int> ve[N], ans;
int cnt[N], L[N], R[N], x[N];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> L[i] >> R[i];
    }
    cin >> p;
    for (int i = 1; i <= p; ++i)
    {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        int st = lower_bound(x + 1, x + 1 + p, L[i]) - x, ed = upper_bound(x + 1, x + 1 + p, R[i]) - x;
        for (int j = st; j <= p && j < ed; ++j)
        {
            ve[i].push_back(x[j]);
        }
        if (!ve[i].empty())
            cnt[i] = ve[i].size();
    }
    for (int i = 1; i <= n; ++i)
    {
        if (cnt[i] > 2)
        {
            cout << "impossible" << endl;
            return;
        }
        if (cnt[i] == 2)
            continue;
        if (cnt[i] == 1)
        {
            if (ve[i].empty() && cnt[i + 1] < 2 && R[i] == L[i + 1])
            {
                ans.push_back(R[i]);
                cnt[i + 1]++;
                continue;
            }
            else if (!ve[i].empty() && ve[i].back() != R[i] && cnt[i + 1] < 2 && R[i] == L[i + 1])
            {
                cnt[i + 1]++;
                ans.push_back(R[i]);
            }
            else
            {
                if (!ve[i].empty() && ve[i][0] != L[i] + 2)
                {
                    ans.push_back(L[i] + 2);
                }
                else
                {
                    ans.push_back(L[i] + 3);
                }
            }
        }
        else if (cnt[i] == 0)
        {
            if (cnt[i + 1] < 2 && R[i] == L[i + 1])
            {
                cnt[i + 1]++;
                ans.push_back(R[i]);
                ans.push_back(L[i] + 2);
            }
            else
            {
                ans.push_back(L[i] + 2);
                ans.push_back(L[i] + 4);
            }
        }
    }
    int alen = ans.size();
    cout << alen << endl;
    for (int i = 0; i < alen; ++i)
    {
        cout << ans[i] << (i == alen - 1 ? '\n' : ' ');
    }
}

int main(void)
{
    solve();
    return 0;
}