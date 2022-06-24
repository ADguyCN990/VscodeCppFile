#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, a, b;
vector<int> A, B;

void solve()
{
    cin >> n >> a >> b;
    if (a + b + 2 > n || abs(a - b) > 1)
    {
        cout << -1 << endl;
        return;
    }
    if (a == b)
    {
        for (int i = n; i >= a + a + 3; i--)
            cout << i << " ";
        for (int i = a + 1; i; i--)
        {
            cout << 2 * a + 3 - i << " ";
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    A.clear(), B.clear();
    bool flag = false;//用于标记波峰多还是波谷多
    if (a > b)
    {
        swap(a,b);
        flag=true;
    }
    for (int i = b; i; i--)
        A.emplace_back(2 * b + 1 - i), A.emplace_back(i);
    for (int i = 2 * b + 1; i <= n; i++)
        B.emplace_back(i);
    if (flag)
    {
        for (int i = 0; i < A.size(); i++)
            cout << n - A[i] + 1 << " ";
        for (int i = 0; i < B.size(); i++)
            cout << n - B[i] + 1 << " ";
        cout << endl;
        return;
    }
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    for (int i = 0; i < B.size(); i++)
        cout << B[i] << " ";
    cout << endl;
    return;
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
