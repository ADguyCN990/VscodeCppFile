#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f3f3f3f3f
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
ll n, m, x, k, y;
ll a[MAXN], b[MAXN];
ll ans = 0;
void solve()
{
    n = read(), m = read(), x = read(), k = read(), y = read();
    for (int i = 1; i <= n; i ++) a[i] = read();
    for (int i = 1; i <= m; i ++) b[i] = read();
    a[n + 1] = 0, b[m + 1] = 0;
    int now = 1;
    for (int i = 1; i <= m + 1; i ++)
    {
        int len = 0;
        ll mx = -1;
        while (a[now] != b[i] && now <= n + 1)
        {
            mx = max(mx, a[now]);
            len ++;
            now ++;
        }
        ll tmp = INF;
        if (now == n + 2) //找不到了
        { 
            puts("-1");
            return;
        }
        for (int j = 1; j * k <= len; j ++)
        {
            tmp = min(tmp, j * x + (len - j * k) * y);
        }
        if (b[i - 1] > mx && i > 1 || b[i] > mx)
            tmp = min(tmp, y * len);
        if (tmp == INF)
        {
            puts("-1");
            return;
        }
        ans += tmp;
        now ++;
    }
    printf("%lld\n", ans);
}

int main()
{
    solve();
    return 0;
}