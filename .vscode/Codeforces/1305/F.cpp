#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define INF 0x3f3f3f3f3f3f3f3f
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int n;
ll a[MAXN];
ll ans = INF;
vector<ll> num;

void check(ll p) {
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        ll need;
        if (a[i] < p) {
            need = p - a[i];
        }
        else {
            ll rem = a[i] % p;
            need = min(rem, p - rem);
        }
        cnt += need;
    }
    ans = min(cnt, ans);
}

void divide(ll now) {
    for (ll j = 2; j <= now / j; j++) {
        if (now % j == 0)
            num.push_back(j);
        while (now % j == 0)
            now /= j;
    }
    if (now != 1)
        num.push_back(now);
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    sort(a + 1, a + 1 + n, greater<>());
    //300 * 2e5
    for (int i = 1; i <= min(n, 20); i++) {
        if (a[i] > 1)
            divide(a[i]);
        if (a[i] > 2)
            divide(a[i] - 1);
        divide(a[i] + 1);
    }
    for (int i = 1; i <= min(n, 20); i++) {
        ll random = rand() * rand() % n + 1;
        if (a[random] > 1)
            divide(a[random]);
        divide(a[random] + 1);
        if (a[random] > 2)
            divide(a[random] - 1);
    }
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    int len = num.size();
    for (int i = 0; i < len; i++) {
        check(num[i]);
        //printf("num: %lld ans: %lld\n", num[i], ans);
    }
    printf("%lld\n", ans);
    return 0;
}