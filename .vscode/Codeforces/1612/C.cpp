#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f
ll k, x;
bool check(ll t) //发了t层塔之后会不会被ban（t-1层<x）
{
    t--;
    ll ans = 0;
    if (t <= k)
    {
        if (t & 1)
            ans = (1 + t) / 2 * t;
        else
            ans = t / 2 * (1 + t);
    }

    else if (t > k)
    {
        ans=(1+k)*k/2;
        ll tmp = t - k;
        if (tmp & 1)
            ans += (k - 1 + k - tmp) / 2 * tmp;
        else
            ans += tmp / 2 * (k - 1 + k - tmp);
    }
    return ans < x;
}

void solve()
{
    cin >> k >> x;
    ll l = 1, r = 2 * k - 1;
    ll ans = 0;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
            //cout<<mid<<" ok!!!"<<endl;
        }
        else
        {
            r = mid - 1;
            //cout<<mid<<" fail!!!"<<endl;
        }
    }
    cout << ans << endl;
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