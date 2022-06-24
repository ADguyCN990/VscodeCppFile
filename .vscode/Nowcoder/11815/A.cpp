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
            a=(a*a) % mod;
        }
    }
    return ans;
}
int n, m;
char s[MAXN];
ll cnt[30];
void solve()
{
    n = read(), m = read();
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i ++) cnt[s[i] - 'a'] ++;
    while (m --)
    {
        int opt;
        opt = read();
        if (opt == 1)
        {
            int k;
            k = read();
            for (int i = 0; i < 26; i ++) cnt[i] = cnt[i] * (k + 1) % mod;
        }
        else
        {
            char tmp[10];
            scanf("%s", tmp);
            int id = tmp[0] - 'a';
            printf("%lld\n", cnt[id] % mod);
        }
    }
}

int main()
{
    solve();
    return 0;
}