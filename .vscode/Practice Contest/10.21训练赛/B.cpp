#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long
#define ull unsigned long long
int n, L, R, cnt, num, ans;
int f[MAXN];
ll a[MAXN];
ull seed;
ull xorshift64()
{
    ull x = seed;
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    return seed = x;
}

int gen()
{
    return xorshift64() % (R - L + 1) + L;
}

ll gcd(ll a, ll b)
{
    if (a < b)
        swap(a, b);
    ll temp;
    while (b)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int findx(int x)
{
    if (x == f[x])
        return x;
    else
        return f[x] = findx(f[x]);
}

void merge(int x, int y, ll val)
{
    int fx = findx(x);
    int fy = findx(y);
    if (fx != fy)
    {
        f[fy] = fx;
        cnt++;
        ans += val;
    }
}

struct node
{
    ll u;
    ll v;
    ll val;
    bool operator<(const node &a) const { return a.val < val; }
};
void solve()
{
    cin >> n >> L >> R >> seed;
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
        a[i] = gen();
    }
    if (L == R)
    {
        cout << (ll)(n - 1) * (ll)L << endl;
        return;
    }
    else if (n >= 3000)
    {
        cout << n - 1 << endl;
        return;
    }
    priority_queue<node> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            q.push(node{i, j, gcd(a[i], a[j])});
        }
    }
    while (!q.empty())
    {
        int u, v, val;
        u = q.top().u;
        v = q.top().v;
        val = q.top().val;
        q.pop();
        merge(u, v, val);
        //if(cnt==n-1) break;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}