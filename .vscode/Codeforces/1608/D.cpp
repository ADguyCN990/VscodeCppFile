#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
#define MAXM 200005
#define mod 998244353
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
ll quickpow(ll a,ll n)
{
    ll ans=1;
    while(n)
    {
        if(n%2==1)
        {
            n--;
            ans=(ans*a) % mod;
        }
        else if(n%2==0)
        {
            n/=2;
            a=(a*a) %mod;
        }
    }
    return ans;
}
ll fac[MAXN],inv[MAXN];
void pre()
{
    fac[0]=1;
    for(int i=1;i<=300000;i++) fac[i]=fac[i-1]*i%mod;
    inv[300000]=quickpow(fac[300000],mod-2);
    for(int i=299999;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}

ll cnm(ll n,ll m)
{
    if(m<0||m>n) return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}

char s[MAXN][5];
ll n, cnt, cntw, cntb, cnt1, cnt2;
void solve()
{
    n = read();
    for (int i = 1; i <= n; i ++)
    {
        scanf("%s", s[i] + 1);
        cnt += s[i][1] != '?' + s[i][2] != '?';
        cntw += s[i][1] == 'W' + s[i][2] == 'W';
        cntb += s[i][1] == 'B' + s[i][2] == 'B';
        cnt1 += (s[i][1] == 'W' && s[i][2] == 'W');
        cnt2 += (s[i][1] == 'B' && s[i][2] == 'B');
    }
    if (cnt1 || cnt2)
    {
        printf("%lld\n", cnm(2 * n - cnt, n - cntw));
        return;
    }
    ll ans = cnm(2 * n - cnt, n - cntw);
    cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (s[i][1] == 'W' || s[i][2] == 'B') cnt1 ++;
        if (s[i][1] == 'B' || s[i][2] == 'W') cnt2 ++;
    }
    if (cnt1 == 0) ans ++;
    if (cnt2 == 0) ans ++;
    ans = (ans + mod - quickpow(2, n - cnt1 - cnt2)) % mod;
    printf("%lld\n", ans);
}

int main()
{
    pre();
    solve();
    return 0;
}