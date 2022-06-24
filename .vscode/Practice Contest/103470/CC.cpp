#include<bits/stdc++.h>
using namespace std;
#define MAXN 5000005
#define X 2000100
int read(){
    int x = 0, f = 1;char ch;
    do{ch=getchar();if (ch=='-') f=-1;}while (ch<'0' || ch>'9');
    do{x=x*10+ch-48;ch=getchar();}while  (ch>='0' && ch<='9');
    return x * f;
}

int sum[MAXN];
int a[MAXN];
int pre[MAXN]; //x和x+k
int n, k;

void solve() {
    n = read(), k = read();
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        a[i] += X;
        sum[a[i]]++;
        mx = max(mx, sum[a[i]]);
    }
    if (!k) {
        printf("%d\n", mx);
        return;
    }
    int ans = mx;
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        pre[x]--;
        if (pre[x] < 0) pre[x] = 0;
        pre[x + k]++;
        ans = max(sum[x + k] + pre[x + k], ans);
    }
    printf("%d\n", ans);
}

int main() {
    solve();
}