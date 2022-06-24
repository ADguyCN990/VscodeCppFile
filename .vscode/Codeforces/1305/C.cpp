#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
ll n, m;
ll a[MAXN];
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    ll ans = 1;
    if (n > m) {
        puts("0");
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ans = ans * abs(a[i] - a[j]) % m;
        }
    }
    printf("%lld\n", ans);
    return 0;
}