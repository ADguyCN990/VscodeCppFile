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
ll b[MAXN];
int main() {
    n = read();
    for (int i = 1; i <= n; i++) b[i] = read();
    a[1] = b[1];
    int mx = a[1];
    for (int i = 2; i <= n; i++) {
        if (b[i] > 0) {
            mx += b[i];
            a[i] = mx;
        }
        else {
            a[i] = mx + b[i];
        }
    }
    for (int i = 1; i <= n; i++) printf("%lld ", a[i]);
}
