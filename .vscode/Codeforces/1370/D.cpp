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

bool check(int mid) {
    //min(max, max) = mid
    //假设有奇数做出答案的贡献
    int odd = 0, even = 0;
    for (int i = 1; i <= n; i++) {
        if (odd & 1) //当前为偶数位，随意
            odd++;
        else if (odd % 2 == 0 && a[i] <= mid)
            odd++;
    }
    //假设由偶数做出答案的贡献
    for (int i = 1; i <= n; i++) {
        if (even % 2 == 0) //当前为奇数位，随意
            even++;
        else if (even % 2 == 1 && a[i] <= mid)
            even++;
    }
    int len = max(odd, even);
    return len >= k;
}

void solve() {
    n = read(), k = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    ll mx = 0;
    for (int i = 1; i <= n; i++) mx = max(mx, a[i]);
    int l = 1, r = mx;
    int ans = INF;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
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