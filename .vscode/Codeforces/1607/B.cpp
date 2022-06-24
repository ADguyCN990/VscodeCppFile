#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, d, now;

void solve()
{
    cin >> now >> n;
    //偶数向左，奇数向右
    ll cnt = n / 4;
    n = n % 4;
    if (now % 2 == 0)
    {
        if (n == 0)
        {
            cout << 0ll + now << endl;
            return;
        }
        else if (n == 1)
        {
            cout << -1 - cnt * 4 + now << endl;
            return;
        }
        else if (n == 2)
        {
            cout << now + 1ll << endl;
            return;
        }
        else if (n == 3)
        {
            cout << (cnt+1) * 4ll + now<< endl;
            return;
        }
    }
    if(n==0)
    {
        cout<<0ll+now<<endl;
    }
    else if(n==1)
    {
        cout<<now+1ll+4ll*cnt<<endl;
    }
    else if(n==2)
    {
        cout<<now-1ll<<endl;
    }
    else if(n==3)
    {
        cout<<now-(cnt+1)*4ll<<endl;
    }
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