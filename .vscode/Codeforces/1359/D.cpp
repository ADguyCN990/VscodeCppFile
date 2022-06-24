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
int n;
int a[MAXN];
unordered_map<int, int> vis;
void solve() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read(), vis[a[i]] = 1;
    ll ans = 0;
    for (int mx = 0; mx <= 30; mx++) {
        //所有的数都是小于等于mx的，mx是被删掉的数
        if (!vis[mx]) continue;
        ll pre = 0, now = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] > mx) {
                now = 0;
                pre = 0;
            }
            else {
                now = max(0ll, pre) + a[i];
                pre = now;
                ans = max(ans, now - mx);
            }
        }
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}