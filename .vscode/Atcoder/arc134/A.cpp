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
ll a[MAXN];
ll n, m, k;
void solve()
{
    n = read(), m = read(), k = read();
    for (int i = 1; i <= n; i ++) a[i] = read();
    ll now = 0;
    ll ans = 0;
    //now表示能到达的最后一个端点
    for (int i = 1; i <= n; i ++)
    {
        //printf("i: %d now: %lld\n", i, now);
        if (a[i] > now)
        {
            ll dif = a[i] - now;
            ans += (dif + k - 1) / k;
        }
        now = a[i] + k;

    }
    if (m > now)
    {
        ll dif = m - now;
        ans += (dif + k - 1) / k;
    }
    printf("%lld\n", ans);
}

int main()
{
    solve();
    return 0;
}