#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 100005;
const int M = 300005;
int n, m;
ll a[N], b[M];

void solve()
{
    priority_queue<ll> aa;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        aa.push(a[i]);
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> b[i];
    }
    sort(b + 1, b + 1 + m);
    int cnt = 0;
    for (int i = 1; i <= m; ++i)
    {
        int v = aa.top();
        if (v < b[i])
            break;
        cnt++;
        v -= b[i];
        aa.pop();
        
        if (v > 0)
        {
            aa.push(v);
        }
    }
    cout << cnt << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}