#include<bits/stdc++.h>
using namespace std;
#define MAXN 5005
#define ll long long
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
ll n, m, k;
ll a[MAXN], sum[MAXN];

int main() {
    n = read(), m = read(), k = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        sum[i] = sum[i - 1] + a[i];
    }
    

    return 0;
}