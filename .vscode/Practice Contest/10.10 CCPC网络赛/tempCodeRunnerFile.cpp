#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
#define MAXN 1000005
string s;
int n;
ll dp[10];
ll nxt[MAXN];
ll ans;

ll quickpow(ll k)
{
    ll res = 1;
    ll x = 2;
    while (k != 0)
    {
        if (k & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        k /= 2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    while (n--)
    {
        for (int i = 0; i < 10; i++)
        {
            dp[i] = 0;
        }
        for (int i = 0; i < MAXN; i++)
        {
            nxt[i] = 0;
        }
        cin >> s;
        ans = 0;
        ll len = (ll)s.length();
        for (ll i = len - 1; i >= 0; i--)//处理后缀的a
        {
            nxt[i] = nxt[i + 1];
            if (s[i] == 'a')
            {
                nxt[i] = nxt[i] + 1 % mod;
            }
        }
        //nunhehheh
        for (int i = 0; i < len; i++)
        {
            if (s[i] == 'n')
            {
                dp[3] = dp[3] + dp[2] % mod;
                dp[1] = dp[1] + 1 % mod;
            }
            if (s[i] == 'u')
            {
                dp[2] = dp[2] + dp[1] % mod;
            }
            if (s[i] == 'e')
            {
                dp[5] = dp[5] + dp[4] % mod;
                dp[8] = dp[8] + dp[7] % mod;
            }
            if (s[i] == 'h')
            {
                dp[4] = dp[4] + dp[3] % mod;
                dp[7] = dp[7] + dp[6] % mod;
                dp[6] = dp[6] + dp[5] % mod;
                dp[9] = dp[9] + dp[8] % mod;
                ans += ((quickpow(nxt[i]) - 1) * dp[8]) % mod;
                ans %= mod;
            }
        }
        cout<<ans<<endl;
    }
}