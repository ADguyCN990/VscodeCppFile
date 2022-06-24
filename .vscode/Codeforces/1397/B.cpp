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
void solve()
{
    int n;
    n = read();
    for (int i = 1; i <= n; i ++)
    {
        a[i] = read();
    }
    sort(a + 1, a + 1 + n);
    ll ans = 1e18;
    for (ll c = 1; ; c ++)
    {
        ll now = 0;
        ll b = c;
        now = abs(1 - a[1]);
        for (int i = 2; i <= n; i ++)
        {
            now += abs(b - a[i]);
            b *= c;
            if (now > ans)
            {
                printf("%lld\n", ans);
                return;
            }
        }
        if (now <= ans) ans = now;
        else 
        {
            printf("%lld\n", ans);
            return;
        }
    }
    
}

int main()
{
    solve();
    
    return 0;
}