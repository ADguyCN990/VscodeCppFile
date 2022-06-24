#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 500005
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
ll sum[MAXN];
void solve() {
    n = read();
    for (int i = 1; i <= (n + 1) / 2; i++) a[i] = read();
    x = read();
    for (int i = (n + 1) / 2 + 1; i <= n; i++) a[i] = x;
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    if (x >= 0) {
        //如果后半部分都为正数，肯定全选上是最优的情况
        if (sum[n] <= 0)
            puts("-1");
        else
            printf("%d\n", n);
        return;
    }
    // 若x < 0, 长度必须要大于 n / 2，为了方便没写
    ll mn = INF;
    for (int i = 1; i <= n; i++) {
        ll tmp = sum[n] - sum[i - 1];
        if (i == 1) {
            mn = tmp;
        }
        else {
            mn = min(mn - x, tmp);
        }
        if (mn > 0) {
            printf("%d\n", n - i + 1);
            return;
        }
            
    }
    puts("-1");
}

int main() {
    solve();
    return 0;
}