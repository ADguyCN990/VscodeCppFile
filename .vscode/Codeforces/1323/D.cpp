#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 400005
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int n;
int a[MAXN];
int cnt[35];

int main() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    ll ans = 0;
    for (int i = 30; i >= 0; i--) { //统计第i位的贡献
        for (int j = 1; j <= n; j++)
            a[j] = a[j] & ((1 << (i + 1)) - 1);
        sort(a + 1, a + 1 + n);
        for (int j = 2; j <= n; j++) {
            int num1 = upper_bound(a + 1, a + j, (1 << (i + 1)) - 1 - a[j]) - lower_bound(a + 1, a + j, (1 << i) - a[j]);
            int num2 = upper_bound(a + 1, a + j, (1 << (i + 2)) - 2 - a[j]) - lower_bound(a + 1, a + j, (1 << (i + 1)) + (1 << i) - a[j]);
            if (num1 + num2 & 1)
                ans ^= 1 << i;
            //printf("i: %d num1: %d num2: %d\n", i, num1, num2);
        }
    }
    printf("%lld\n", ans);
    return 0;
}