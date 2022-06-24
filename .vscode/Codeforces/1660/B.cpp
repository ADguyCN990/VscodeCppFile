#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
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
    if (n == 1) {
        if (a[1] == 1) 
            puts("YES");
        else
            puts("NO");
        return;
    }
    sort(a + 1, a + 1 + n, greater<>());
    if (a[1] - a[2] <= 1) {
        puts("YES");
        return;
    }
    puts("NO");
}

int main() {
    int t = read();
    while (t--)
        solve();
    return 0;
}

