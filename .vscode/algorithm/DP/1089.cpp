#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
ll n, k;
ll sum[MAXN];
ll ans = -1;
int hh = 1, tt = 0;
int q[MAXN];
ll dp[MAXN];
void solve() {
    n = read(), k = read();
    for (int i = 1; i <= n; i++) {
        sum[i] = read();
        sum[i] += sum[i - 1];
    }
    q[++tt] = 0;
    for (int i = 1; i <= n; i++) {
        while (hh <= tt && i - q[hh] > k) hh++;
        ans = max(ans, sum[i] - sum[q[hh]]);
        while (hh <= tt && sum[i] >= sum[q[tt]]) tt--;
        q[++tt] = i;
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}