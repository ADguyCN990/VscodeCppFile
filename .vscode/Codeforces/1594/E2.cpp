#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<ll, ll> pii;
#define INF 0x3f3f3f3f
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define per(i, x, y) for (int i = x; i >= y; i--)
#define pb emplace_back
#define mod 1000000007
ll quickpow(ll a, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n % 2 == 1)
        {
            n--;
            ans = (ans * a) % mod;
        }
        else if (n % 2 == 0)
        {
            n /= 2;
            a = (a * a) % mod;
        }
    }
    return ans;
}
ll k, m;
map<string, int> mp;
map<ll, int> path; //是否需要访问这个节点
map<pii, ll> dp;   //存储方案数
map<ll, int> color;
vector<int> edge[10];
ll base[65];
void pre()
{
    mp["white"] = 1;
    mp["yellow"] = 2;
    mp["green"] = 3;
    mp["blue"] = 4;
    mp["red"] = 5;
    mp["orange"] = 6;
    edge[1] = {3, 4, 5, 6};
    edge[2] = {3, 4, 5, 6};
    edge[3] = {1, 2, 5, 6};
    edge[4] = {1, 2, 5, 6};
    edge[5] = {1, 2, 3, 4};
    edge[6] = {1, 2, 3, 4};
    base[0]=1;
    for(int i=1;i<=60;i++) base[i]=base[i-1]*2;
}
ll dfs(ll now, int col)
{
    if (dp.count({now,col})) //冗余性剪枝
    {
        return dp[{now, col}];
    }
    if (color[now] != col && color[now] != 0) //可行性剪枝
    {
        return 0;
    }
    ll cnt1 = 0, cnt2 = 0;
    ll ans = 1;
    if (path[now * 2] > 0) //左子树有被染色的
    {
        for (int i = 0; i < 4; i++)
        {
            cnt1 = (cnt1 + dfs(now * 2, edge[col][i])) % mod;
        }
        ans = cnt1;
    }
    if (path[now * 2 + 1] > 0) //右子树有被染色的
    {
        for (int i = 0; i < 4; i++)
        {
            cnt2 = cnt2 + dfs(now * 2 + 1, edge[col][i]) % mod;
        }
        ans = (ans * cnt2) % mod;
    }
    //cout<<dp[{now,col}]<<endl;
    return dp[{now, col}] = ans;
}
void solve()
{
    cin >> k >> m;
    ll limit = 0;
    dp.clear(), color.clear();
    for (int i = 1; i <= m; i++)
    {
        ll t;
        string cc;
        cin >> t >> cc;
        int c = mp[cc];
        color[t] = c;
        while (t > 0)
        {
            if(path[t]) break;
            limit++;
            path[t] = 1;
            t /= 2;
        }
    }
    ll tot = (long long)(base[k]) - 1 - limit;
    ll ans = quickpow(4, tot) % mod;
    ll left = 0;
    for (int i = 1; i <= 6; i++)
    {
        left = (left + dfs(1, i)) % mod;
    }
    //cout<<"ans: "<<ans<<" left: "<<left<<" tot: "<<tot<<endl;
    cout << ans * left % mod << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pre();
    solve();
    return 0;
}