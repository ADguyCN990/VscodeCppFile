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

ll cnm(ll n, ll m) {
    ll up = 1;
    for (int i = 1; i <= m; i++) up *= n;
    return up;
}

void solve() {
    ll now = 0; //当前到了第几个回答
    ll chcnt = 1; //当前字符总数
    ll ans = 0;
    ll n = read(), k = read();
    while (now + cnm(k, chcnt) < n) {
        ans += chcnt * cnm(k, chcnt);
        now += cnm(k, chcnt);
        //printf("now: %lld\n", now);
        chcnt++;
    }
    ans += chcnt * (n - now) ;
    printf("%lld\n", ans);
}

int main() {
    int T = read();
    while (T--) {
        solve();
    }
    return 0;
}