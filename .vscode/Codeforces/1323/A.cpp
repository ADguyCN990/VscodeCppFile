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
int n;
int a[MAXN];

void solve() {
    n = read();
    int even = -1;
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        if (!(a[i] & 1)) {
            even = i;
        }
    }
    if (even != -1) {
        printf("1\n%d\n", even);
        return;
    }
    if (n != 1) {
        puts("2\n1 2");
        return;
    }
    puts("-1");
}

int main() {
    int t = read();
    while (t--)
        solve();
    return 0;
}