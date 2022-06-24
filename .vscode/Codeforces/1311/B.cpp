#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int a[MAXN], b[MAXN], c[MAXN];;
int n, m;

void solve() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) a[i] = read(), c[i] = a[i];
    for (int i = 1; i <= m; i++) b[i] = read();
    sort(b + 1, b + 1 + m);
    sort(c + 1, c + 1 + n);
    int l = b[1];
    for (int i = 2; i <= m; i++) {
        if (b[i] == b[i - 1] + 1) continue;
        //printf("l: %d r: %d\n", l, b[i - 1] + 1);
        sort(a + l, a + 1 + b[i - 1] + 1);
        l = b[i];
    }    
    sort(a + l, a + 1 + b[m] + 1);
    for (int i = 1; i <= n; i++) {
        if (a[i] != c[i]) {
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