#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long
int st[1000005];
int a[MAXN], pre[MAXN];
int n, q;
int read() {
    int x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int main() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    q = read();
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, a[i]);
        pre[i] = pre[i - 1] + a[i];
    }
    while (q--) {
        int t = read();
        if (st[t] != 0) {
            printf("%d\n", st[t]);
            continue;
        }
        if (t < mx) {
            puts("Impossible");
            continue;
        }
        int ans = 0, now = 0, sum;
        while (now < n) {
            sum = pre[now] + t;
            int pos = upper_bound(pre + now, pre + 1 + n, sum) - pre - 1;
            ans++, now = pos;
        }
        st[t] = ans;
        printf("%d\n", ans);
    } 

    return 0;
}
