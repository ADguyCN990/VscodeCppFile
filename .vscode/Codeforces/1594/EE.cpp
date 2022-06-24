#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<ll, ll> pll;
#define xx first
#define yy second
#define endl "\n"
int k, n;
const ll MOD = 1e9 + 7;
map<string, int> c = {{"white", 1}, {"yellow", 2}, {"green", 3}, {"blue", 4}, {"red", 5}, {"orange", 6}};
vector<int> edge[7];
map<pll, ll> f;
map<ll, int> def;
set<ll> ms;
ll p[64];
ll qmi(ll m, ll k, ll MOD)
{
    ll res = 1LL % MOD, t = m;
    while (k)
    {
        if (k & 1)
            res = res * t % MOD;
        t = t * t % MOD;
        k >>= 1;
    }
    return res;
}
void init()
{
    edge[1] = {3, 4, 5, 6};
    edge[2] = {3, 4, 5, 6};
    edge[3] = {1, 2, 5, 6};
    edge[4] = {1, 2, 5, 6};
    edge[5] = {1, 2, 3, 4};
    edge[6] = {1, 2, 3, 4};
    p[0] = 1;
    for (int i = 1; i < 64; ++i)
    {
        p[i] = p[i - 1] + p[i - 1];
    }
}
ll dfs(ll cur, int color)
{
    if (f.count(pll(cur, color)))
    {
        return f[pll(cur, color)];
    }
    ll a1 = 0, a2 = 0;
    ll ans = 1;
    if (def.count(cur))
    {
        if (color != def[cur])
            return 0;
    }
    if (ms.count(cur + cur))
    {
        for (auto i : edge[color])
        {
            a1 = a1 + dfs(cur + cur, i) % MOD;
        }
        ans = a1 % MOD;
    }
    if (ms.count(cur + cur + 1))
    {
        for (auto i : edge[color])
        {
            a2 = a2 + dfs(cur + cur + 1, i) % MOD;
        }
        ans = (ans * a2) % MOD;
    }
    return f[pll(cur, color)] = ans;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll id;
    string color;
    init();
    cin >> k >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> id >> color;
        def[id] = c[color];
    }
    for (map<ll, int>::iterator iter = def.begin(); iter != def.end(); iter++)
    {
        id = iter->xx;
        while (id != 0)
        {
            ms.insert(id);
            id /= 2;
        }
    }
    ll ans = 0;
    for (int i = 1; i < 7; ++i)
    {
        ans = (ans + dfs(1, i)) % MOD;
    }
    ll exp = (p[k] - 1 - ms.size());
    ll mix = qmi(4, exp, MOD);
    ll res = mix * ans % MOD;
    cout << res << endl;
    if(n==2000)
    {
        cout<<mix<<" "<<ans<<" "<<exp<<endl;
    }
    return 0;
}