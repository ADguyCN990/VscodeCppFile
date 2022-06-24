#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

int main() {
    ll u = read(), v = read();
    //xor-sum = u, sum = v
    vector<ll> num;
    ll tmp = v - u;
    if (tmp < 0 || tmp & 1) {
        puts("-1");
        return 0;
    }
    if (u == 0 && v == 0) {
        puts("0");
        return 0;
    }
    if (tmp == 0) {
        printf("1\n%lld", u);
        return 0;
    }
    tmp >>= 1;
    if (u & tmp) {
        printf("%d\n%lld %lld %lld\n", 3, u, tmp, tmp);
    }
    else {
        printf("%d\n%lld %lld\n", 2, u + tmp, tmp);
    }
    return 0;
}
