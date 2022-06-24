#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 2005
#define MAXM 200005
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
int n, m;
char mp[MAXN][MAXN];
ll up[MAXN][MAXN]; //上三角
ll down[MAXN][MAXN]; //下三角
ll l[MAXN][MAXN], r[MAXN][MAXN];
void init()
{
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            up[i][j] = 1, down[i][j] = 1, l[i][j] = 1, r[i][j] = 1;
   
}

void solve()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i ++)
        scanf("%s", mp[i] + 1);
    init();
    for (int i = 1; i <= n; i ++) //预处理l[i][j]
        for (int j = 1; j <= m; j ++)
            if (mp[i][j] == mp[i][j - 1])
                l[i][j] = l[i][j - 1] + 1;
    for (int i = 1; i <= n; i ++) // 预处理r[i][j]
        for (int j = m; j >= 1; j --)
            if (mp[i][j] == mp[i][j + 1])
                r[i][j] = r[i][j + 1] + 1;
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            if (mp[j][i] == mp[j - 1][i])
                up[j][i] = min({up[j - 1][i] + 1, l[j][i], r[j][i]});
    for (int i = 1; i <= m; i ++)
        for (int j = n; j >= 1; j --)
            if (mp[j][i] == mp[j + 1][i])
                down[j][i] = min({down[j + 1][i] + 1, l[j][i], r[j][i]});
    ll ans = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            ans += min(up[i][j], down[i][j]);
    printf("%lld\n", ans);
}

int main()
{
    solve();
    return 0;
}