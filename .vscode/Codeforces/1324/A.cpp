#include<bits/stdc++.h>
using namespace std;
#define MAXN 105
#define ll long long
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
ll n;
ll a[MAXN];

void solve() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 2; i <= n; i++) {
        if (abs(a[i] - a[i - 1]) & 1) {
            puts("NO");
            return;
        }
    }
    puts("YES");
}

int main() {
    int t = read();
    while (t--)
        solve();
    return 0;
}