#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

void solve() {
    ll n = read(), k = read();
    if (k * k > n) {
        puts("NO");
        return;
    }
    if (n % 2 == k % 2)
        puts("YES");
    else
        puts("NO");
}

int main() {
    int T = read();
    while (T--)
        solve();
    return 0;
}