#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
ll n, m, p;
ll a[MAXN], b[MAXN];

int main() {
    n = read(), m = read(), p = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= m; i++) b[i] = read();
    ll x = -1, y = -1;
    for (int i = 1; i <= n; i++) {
        if (a[i] % p && x == -1) {
            x = i - 1;
            break;
        }
    }
    for (int i = 1; i <= m; i++) {
        if (b[i] % p && y == -1) {
            y = i - 1;
            break;
        }
    }
    //printf("x: %lld y: %lld\n", x, y);
    printf("%lld\n", x + y);
    return 0;
}