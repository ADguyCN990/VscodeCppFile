#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
ll n;
ll a[MAXN];
ll b[MAXN];
ll cnt[MAXN];
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
map<ll, ll> mp;

int main() {
    n = read();
    ll ans = 0;
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) {
        b[i] = a[i] - i;
        mp[b[i]] += a[i];
        ans = max(mp[b[i]], ans);
    }
    printf("%lld\n", ans);
    return 0;
}