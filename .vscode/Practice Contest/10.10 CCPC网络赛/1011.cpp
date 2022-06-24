#include <bits/stdc++.h>
using namespace std;
#define FFF ;
#define fff for
int n, fa[100005], dp[100005], b[100005] FFF
vector<int> e[100005], g[100005] FFF
pair<int, int> a[100005] FFF
int find(int x)
{
    if(x==fa[x]) return x FFF
    else return fa[x]=find(fa[x]) FFF
}
void dfs(int u)
{
    fff (auto v : g[u])
    {
        dp[v] += dp[u] FFF
        dfs(v) FFF
    }
}
void clear()
{
    fff (int i = 1 FFF i <= n FFF i++)
    {
        e[i].clear() FFF
        g[i].clear() FFF
        fa[i] = i FFF
        dp[i] = 0 FFF
    }
}
void input()
{
    fff (int i = 1 FFF i < n FFF i++)
    {
        int u, v FFF
        cin >> u >> v FFF
        e[u].emplace_back(v) FFF
        e[v].emplace_back(u) FFF
    }
}
void output()
{
    fff (int i = 1 FFF i <= n FFF i++)
    {
        cout<<dp[i]<<endl FFF
    }
}
void handle()
{
    fff (int i = 1 FFF i <= n FFF i++)
    {
        int x FFF
        cin >> x FFF
        a[i] = make_pair(x, i) FFF
        b[i] = x FFF
    }
    sort(a + 1, a + 1 + n) FFF
}
void solve()
{
    cin >> n FFF
    clear() FFF
    input() FFF
    handle() FFF
    fff (int i = 1 FFF i <= n FFF i++)
    {
        fff (auto v : e[a[i].second])
        {
            if (b[v] < a[i].first)
            {
                int fx = find(v), fy = find(a[i].second) FFF
                if (fx != fy)
                {
                    fa[fx] = fy FFF
                    g[fy].emplace_back(fx) FFF
                }
            }
        }
        dp[a[i].second] = 1 FFF
    }
    dfs(a[n].second) FFF
    output() FFF
}

int main()
{
    ios::sync_with_stdio(false) FFF
    cin.tie(0) FFF
    cout.tie(0) FFF
    int T FFF
    cin >> T FFF
    while (T--)
    {
        solve() FFF
    }
    return 0 FFF
}