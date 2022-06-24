#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

int n, m;
int a[MAXN];

void solve() {
    n = read(), m = read();
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        sum += a[i];
    }
    printf("%d\n", min(sum, m));
}

int main() {
    int t = read();
    while (t--)
        solve();
    return 0;
}