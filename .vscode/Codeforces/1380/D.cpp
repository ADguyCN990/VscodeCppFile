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
void solve()
{
    n = read(), m = read();
    x = read(), k = read(), y = read();
    for (int i = 1; i <= n; i ++) a[i] = read();
    for (int i = 1; i <= m; i ++) b[i] = read();
    a[n + 1] = 0, b[n + 1] = 0;
    int now = 1;
    ll ans = 0;
    for (int i = 1; i <= m + 1; i ++)
    {
        int len = 0;
        ll mx = -1; //区间最值，判断是不是端点
        // 一开始的now相当于起点+1
        while (now <= n && a[now] != b[i]) 
        {
            mx = max(mx, a[now]);
            now ++;
            len ++;           
        }
        //区间：( b[i - 1], b[i] ) 端点保留
        if (now == n + 2) //找不到了
        {
            puts("-1");
            return;
        }
        ll tmp = INF;
        for (int j = 1; j * k <= len; j ++) //使用j次连片击杀
        {
            tmp = min(tmp, j * x + (len - j * k) * y);
        }
        if (mx < b[i] || mx < b[i - 1] && i - 1 > 0) //端点是区间最值可以试试全部使用狂乱击杀
            tmp = min(tmp, len * y);
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