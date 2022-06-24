#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
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
ll n;
ll ans, last, now;
ll h[MAXN], k[MAXN];
void solve()
{
    n = read();
    ans = 0;
    rep (i, 1, n) k[i] = read();
    rep (i, 1, n) h[i] = read();
    per (i, n, 1)
    {
        if (i == n || now > k[i])
        {
            ans += h[i] * (h[i] + 1) / 2;
            now = k[i] - h[i] + 1;
            last = k[i];
        }
        else
        {
            if (k[i] - now + 1 >= h[i]) continue;
            ll x = last - now + 1;
            ll y = h[i] - (k[i] - now + 1);
            ans += y * (y + 1) / 2 + x * y;
            now -= y; 
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