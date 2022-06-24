#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
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
ll a[MAXN];
ll t[MAXN];
ll sum[MAXN];
ll n, q;

ll find(ll x) /*第一个大于x的位置*/{ 
    int l = 1, r = n;
    ll ans = n + 1;
    while (l <= r) {
        ll mid = l + r >> 1;
        if (a[mid] > x) {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}


void solve() {
    n = read(), q = read();
    for (int i = 1; i <= n; i ++) {
        t[i] = read();
    }
    n --;
    for (int i = 1; i <= n; i ++) {
        a[i] = t[i + 1] - t[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + a[i];
    while (q--) {
        ll k, p; //需要入睡的时间，睡眠要达到的时间
        k = read(), p = read();
        int pos = find(k);
        ll ans = sum[n] - sum[pos - 1];
        ans -= k * (n - pos + 1);
        if (ans >= p)
            puts("Yes");
        else
            puts("No");
    }
}

int main() {
    solve();
    return 0;
}