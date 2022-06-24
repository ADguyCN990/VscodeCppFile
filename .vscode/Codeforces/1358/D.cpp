#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 400005
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
ll n, x;
ll a[MAXN];
ll val[MAXN]; //某个月拥抱次数max的个数
ll sum[MAXN]; //人数前缀和
ll pre[MAXN]; //拥抱前缀和
ll get(int i, int x) {
    //一个月的最后x天去摆放得到的拥抱数
    return (a[i] + a[i] + 1 - x) * x / 2;
}

void solve() {
    n = read(), x = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i < n; i++) a[i + n] = a[i];
    for (int i = 1; i <= n; i++) val[i] = (1ll + a[i]) * a[i] / 2;
    for (int i = 1; i < n; i++) val[i + n] = val[i];  
    for (int i = 1; i < 2 * n; i++) sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i < 2 * n; i++) pre[i] = pre[i - 1] + val[i];
    ll ans = 0;
    for (int i = n; i < 2 * n; i++) {
        //第(i-n+1)个月份的最后一天停止假期
        if (x <= a[i]) {
            if (i == n)
                ans = max(ans, get(i, x));
            else
                ans = max(ans, get(i - n, x));
            continue;
        }
        //[tmp,i]，tmp为残缺部分，[tmp+1,i]都是满的
        int l = 1, r = i - 1;
        int tmp;
        while (l <= r) {
            int mid = l + r >> 1;
            if (sum[i] - sum[mid - 1] >= x) {
                tmp = mid;
                l = mid + 1;
            } 
            else
                r = mid - 1;
        }
        ll rem = x - (sum[i] - sum[tmp]);
        ll ans1 = pre[i] - pre[tmp];
        if (tmp > n) tmp = tmp - n;
        ans = max(ans, ans1 + get(tmp, rem));
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}