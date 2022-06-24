#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
#define mod 1000000007
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define pb emplace_back
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
ll n, m;
ll p[MAXN];
vector <int> mp[MAXN];
ll cnt[MAXN], idx; // 每条边被经过的次数
ll siz[MAXN]; // 子树大小
void init()
{
    for (int i = 1; i <= n; i ++) mp[i].clear(), siz[i] = 1, cnt[i] = 0;
    idx = 0;
}

void dfs(int now, int pre)
{
    for (int to : mp[now])
    {
        if (to == pre) continue;
        dfs(to, now);
        siz[now] += siz[to];
        cnt[++ idx] = siz[now] * (n - siz[now]);
    }   
}

void solve()
{
    n = read();
    init();
    for (int i = 1; i < n; i ++) 
    {
        int u, v;
        u = read(), v = read();
        mp[u].pb(v);
        mp[v].pb(u);
    }
    m = read();
    for (int i = 1; i <= m; i ++) p[i] = read();
    dfs(1, -1);
    ll ans = 0;

    if (m < n - 1) //必须有些边为1
    {
        sort(cnt + 1, cnt + 1 + idx, greater<ll>());
        sort(p + 1, p + 1 + m, greater<ll>());
        for (int i = 1; i <= m; i ++)
        {
            ans = (ans + cnt[i] * p[i] % mod) % mod;
        }
        for (int i = m + 1; i <= idx; i ++)
        {
            ans = (ans + cnt[i]) % mod;
        }
    }
    else //边的数量太少了
    {
        sort(cnt + 1, cnt + 1 + idx);
        sort(p + 1, p + 1 + m);
        for (int i = idx + 1; i <= m; i ++)
        {
            p[idx] = p[idx] * p[i] % mod;
        }
        for (int i = 1; i <= idx; i ++)
        {
            ans = (ans + cnt[i] * p[i] % mod) % mod;
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    int T;
    T=read();
    while(T--)
    {
        solve();
    }

    return 0;
}