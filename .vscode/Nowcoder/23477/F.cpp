#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define mod 1000000007
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
char s[MAXN];
int n, q;
ll a[MAXN];
ll tmp[MAXN];
int id[MAXN];
int idx = 1;

ll quickpow(ll a, ll b)
{
    if (b == 0) return 1;
    if (b % 2) return a % mod * quickpow(a * a % mod, b / 2) % mod;
    return quickpow(a * a % mod, b / 2) % mod;
}

void solve()
{
    n = read(), q = read();
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i ++) a[i] = read();
    id[1] = 1;
    tmp[1] = a[1];
    for (int i = 2; i <= n; i ++)
    {
        char c = s[i - 1];
        if (c == '+')
        {
            idx ++;
            id[i] = idx;
            tmp[idx] = a[i];
        }
        else
        {
            id[i] = idx;
            tmp[idx] = tmp[idx] * a[i] % mod;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= idx; i ++) ans = (ans + tmp[i]) % mod;
    while (q --)
    {
        ll pos, x;
        pos = read(), x = read();
        int now = id[pos];
        ans -= tmp[now];
        ll from = tmp[now], to = quickpow(a[pos], mod - 2);
        from = from * to % mod;
        from = from * x % mod;
        tmp[now] = from;
        ans = (ans + mod + tmp[now]) % mod;
        a[pos] = x;
        printf("%lld\n", ans);
    }

}

int main()
{
    solve();
    return 0;
}