#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define per(i, x, y) for(int i = x; i >= y; i--)
#define pb emplace_back
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
ll n, k;
ll a[MAXN];
int istop[MAXN];
int sum[MAXN];
void solve() {
    n = read(), k = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    istop[1] = 0, istop[n] = 0;
    for (int i = 2; i < n; i++) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1])
            istop[i] = 1;
        else
            istop[i] = 0;
    }
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + istop[i];
    int ans = 1;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        int j = i + k - 1;
        if (j > n) break;
        int tmp = sum[j - 1] - sum[i];
        if (tmp > mx) {
            mx = tmp;
            ans = i;
        }
    }
    printf("%d %d\n", mx + 1, ans);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}