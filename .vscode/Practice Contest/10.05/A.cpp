#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, k;

// yikaishi fang k ge


ll solve(){
    ll res = 100000;
    for (ll i=1;i<k;++i){
        ll sum = i, b = i, count = 1;
        sum = b + min(b, (n - b) / 2);
        b = sum;
        if (sum >= n)
        {
            return count;
        }
    while (n-sum > k-i && count <= 10000)
    {
        count++;
        sum = b + min(b, (n - b) / 2);
        b = sum;
    }
    if (sum >= n)
    {
        res = min(res, count);
    }
    else{
        res = min(res, count+1);
    }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    if ((k+min(k, (n-k)/2)) >= n)
    {
        cout << 1 << endl;
        return 0;
    }
    ll res5 = solve();
    cout << res5 << endl;
    return 0;
}