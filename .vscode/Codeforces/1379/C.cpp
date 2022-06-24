#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
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
ll n, m;
struct node
{
    ll a, b;
    friend bool operator < (node a, node b)
    {
        return a.a > b.a;
    }
}a[MAXN];
ll sum[MAXN];

void solve()
{
    m = read(), n = read();
    for (int i = 1; i <= n; i ++)
    {
        a[i].a = read(), a[i].b = read();
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + a[i].a;
    ll ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        int l = 1, r = n;
        ll cnta = 0;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (a[mid].a >= a[i].b)
            {
                cnta = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        if (cnta >= m)
            ans = max(ans, sum[m]);
        else
        {
            if (cnta >= i)
                ans = max(ans, sum[cnta] + a[i].b * (m - cnta));
            else
                ans = max(ans, sum[cnta] + a[i].a + a[i].b * (m - cnta - 1));
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