#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
#define INF 0x3f3f3f3f3f3f3f3f
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int n, k;
ll sum[MAXN], a[MAXN];
int q[MAXN];
int hh = 1, tt = 0;
void solve() {
    n = read(), k = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        sum[i] = sum[i - 1] + a[i]; 
    }
    ll ans = -INF;
    //枚举以i作为终点的，长度不超过k的最大子序和
    q[++tt] = 0;
    for (int i = 1; i <= n; i++) {
        while (hh <= tt && i - q[hh] > k) hh++;
        ans = max(ans, sum[i] - sum[q[hh]]);
        while (hh <= tt && sum[q[tt]] >= sum[i]) tt--;
        q[++tt] = i;
        
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}