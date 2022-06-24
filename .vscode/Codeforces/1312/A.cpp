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
    int n = read(), m = read();
    if (n % m == 0) {
        puts("YES");
    }
    else
        puts("NO");
}

int main() {
    int t = read();
    while (t--)
        solve();
    return 0;
}
