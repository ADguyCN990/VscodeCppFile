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
ll n;
ll a[MAXN];
void solve() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    ll sum = 0, ans = 0;
    ll pos = 0, neg = 0;
    //+-+-+-+-
    if (a[1] == 0) {
        sum = 1;
        ans = 1;
    }
    else if (a[1] > 0) {
        sum = a[1];
        ans = 0;
    }
    else if (a[1] < 0) {
        sum = 1;
        ans = 1 - a[1];
    }
    for (int i = 2; i <= n; i++) {
        if (i & 1) {
            //奇数位，应当为正
            //此时sum小于0
            if (a[i] + sum > 0) {
                sum += a[i];
            }
            else {
                ll need = 1 - sum;
                sum = 1;
                ans += need - a[i];
            }
        }
        else {
            //偶数位，应当为负
            //此时sum大于0
            if (a[i] + sum < 0) {
                sum += a[i];
            }
            else {
                ll need = sum + 1;
                sum = -1;
                ans += a[i] + need;
            }
        }
    }
    pos = ans;
    ans = 0;
    sum = 0;
    //-+-+-+
    if (a[1] == 0) {
        sum = -1;
        ans = 1;
    }
    else if (a[1] < 0) {
        sum = a[1];
        ans = 0;
    }
    else {
        sum = -1;
        ans = a[1] + 1;
    }
    for (int i = 2; i <= n; i++) {
        if (i & 1) {
            //奇数位，应当为负
            //此时sum应当大于0
            if (a[i] + sum < 0) {
                sum += a[i];
            }
            else {
                ll need = sum + 1;
                sum = -1;
                ans += a[i] + need;
            }
        }
        else {
            //偶数位，应当为正
            //此时sum应当小于0
            if (a[i] + sum > 0) {
                sum += a[i];
            }
            else {
                ll need = 1 - sum;
                sum = 1;
                ans += need - a[i];
            }
        }
    }
    neg = ans;
    ans = min(neg, pos);
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}