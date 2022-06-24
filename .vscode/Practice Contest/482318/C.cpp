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
int a[MAXN], b[MAXN];
ll c[MAXN];
ll sum[MAXN];
void solve() {
    n = read(), k = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read(), b[i] = read();
        c[a[i]] += b[i];
    }
    for (int i = 1; i <= 100000; i++) sum[i] = sum[i - 1] + c[i];
    int l = 1, r = 100000;
    int ans;
    while (l <= r) {
        int mid = l + r >> 1;
        if (sum[mid] >= k ) {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}