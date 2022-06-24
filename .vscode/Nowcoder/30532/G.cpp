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
ll n, a, b;
char s[MAXN];

int main() {
    n = read(), a = read(), b = read();
    scanf("%s", s + 1);
    ll l = 1, r = 1;
    ll sum1 = 0, sum0 = 0;
    if (a == 0 && b == 0) {
        printf("%lld\n", n * (n + 1) / 2 + 1);
        return 0;   
    }
    if (s[l] == '0') sum0++;
    else sum1++;
    ll ans = 0;
    while (l <= n) {
        while (r <= n && (sum0 < a || sum1 < b)) {
            r++;
            if (s[r] == '1') sum1++;
            else sum0++;
        }
        if (sum0 < a || sum1 < b) break;
        ans += n - r + 1;
        if (s[l] == '0') sum0--;
        else sum1--;
        l++;
    }
    printf("%lld\n", ans);
}