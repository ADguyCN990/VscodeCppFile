#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, id;
const int Max_n = 4e5 + 10;
const ll MOD1 = 1e9 + 7, MOD2 = 1e9 + 11;
char s[Max_n];
ll hs1[Max_n], hs2[Max_n], peac1[Max_n], peac2[Max_n];
ll p = 131;
pair<ll, ll> res[Max_n];
map<pair<ll, ll>, ll> cnt;
ll ans;
ll q1(int le, int ri)
{
    return (hs1[ri] - hs1[le - 1] * peac1[ri - le + 1] % MOD1 + MOD1) % MOD1;
}
ll q2(int le, int ri)
{
    return (hs2[ri] - hs2[le - 1] * peac2[ri - le + 1] % MOD2 + MOD2) % MOD2;
}
pair<ll, ll> query(int le, int ri)
{
    return pair<ll, ll>(q1(le, ri), q2(le, ri));
}
void init()
{
    id = 0, peac1[0] = 1, peac2[0] = 1;
    for (int i = 1; i < Max_n; ++i)
    {
        peac1[i] = peac1[i - 1] * p % MOD1;
        peac2[i] = peac2[i - 1] * p % MOD2;
    }
}

void solve()
{
    init();
    cin>>n;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", s + 1);
        int slen = strlen(s + 1);
        for (int j = 1; j <= slen; ++j)
        {
            hs1[j] = (hs1[j - 1] * p % MOD1 + (s[j] - 'a' + 1)) % MOD1;
            hs2[j] = (hs2[j - 1] * p % MOD2 + (s[j] - 'a' + 1)) % MOD2;
        }
        cnt[pair<ll,ll>(hs1[slen], hs2[slen])]++;
        for (int j = 1; j + j < slen; ++j)
        {
            if (query(1, j) == query(slen - j + 1, slen))
            {
                id++;
                res[id] = query(j + 1, slen - j);
            }
        }
    }
    for (int i = 1; i <= id; ++i)
    {
        ans += cnt[res[i]];
    }
    for (auto i : cnt)
    {
        ans = ans + i.second * (i.second - 1) / 2;
    }
    printf("%lld\n", ans);
}

int main()
{
    solve();
    return 0;
}