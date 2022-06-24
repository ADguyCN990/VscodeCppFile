#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a,ll b)
{
    if(a<b) swap(a,b);
    ll tmp;
    while(b)
    {
       tmp=b;
       b=a%b;
       a=tmp; 
    }
    return a;
}
void solve()
{
    ll a, b;
    cin >> a >> b;
    ll GCD = gcd(a, b);
    a /= GCD;
    b /= GCD;
    GCD = gcd(a, 180ll);
    ll LCM = 180 / GCD;
    cout << LCM * b - 1 << endl;
}

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}