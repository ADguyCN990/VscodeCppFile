#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
#define mod 1000000007
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define per(i, x, y) for(int i = x; i >= y; i--)
#define pb emplace_back
ll read() {
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
const int N=30005;
int prime[N+5];
map <int, ll> mp; //最大数
void getprime()
{
    for(int i=2;i<=N;i++)
    {
        if(!prime[i])
            prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<=N/i;j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0)
                break;
        }
    }
    for (int i = 1; i <= prime[0]; i++) {
        mp[prime[i]] = 0;
        //printf("%d\n", prime[i]);
    }
}
int l, r;
void solve() {
    l = read(), r = read();
    for (int i = l; i <= r; i ++) {
        if (mp.count(i)) continue; //是质数，不用管
        int x = i;
        for (int j = 2; j <= x / j; j ++) {
            if (x % j == 0) {
                ll s = 0;
                while (x % j == 0) x /= j, s ++;
                mp[j] = max(mp[j], s);
                //printf("num: %d mx: %lld\n", j, mp[j]);
            }
        }
        if (x > 1) mp[x] = max(mp[x], 1ll);
    }
    ll ans = 1;
    for (auto it : mp) {
        ll num = it.first;
        ll cnt = it.second;
        ans = (ans * quickpow(num, cnt) % mod) % mod;
    }
    if (ans == 1)
        puts("-1");
    else
        printf("%lld\n", ans);
}

int main() {
    getprime();
    solve();
    return 0;
}