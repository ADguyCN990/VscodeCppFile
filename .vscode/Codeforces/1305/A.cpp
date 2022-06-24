#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
int n;
int a[MAXN], b[MAXN];
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

void solve() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) b[i] = read();
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    puts("");
    for (int i = 1; i <= n; i++) printf("%d ", b[i]);
    puts("");
}

int main() {
    int t = read();
    while (t--)
        solve();
    return 0;
}