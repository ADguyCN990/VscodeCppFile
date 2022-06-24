#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 35
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
ll n, k;
ll a[MAXN];
int cnt[65];

void solve() {
    n = read(), k = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i++) {
        ll now = a[i];
        vector<int> base;
        while (now) {
            base.push_back(now % k);
            now /= k;
        }

        for (int j = 0; j < base.size(); j++) {
            cnt[j] += base[j];
            if (cnt[j] > 1) {
                puts("NO");
                return;
            }
        }
    }
    puts("YES");
}

int main() {
    int t = read();
    while (t--)
        solve();
    return 0;
}