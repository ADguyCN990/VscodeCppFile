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
map<ll, int> cnt;
void solve() {
    n = read(), k = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    cnt.clear();
    for (int i = 1; i <= n; i++) cnt[a[i]]++;
    int ans = 0;
    for (auto it : cnt) {
        int id = it.first;
        int num = it.second;
        if (!num) continue;
        while (num) {
            if (!cnt.count(id * k) || !cnt[id * k]) break;
            num--;
            cnt[id * k]--;
        }
        ans += num;
    }
    printf("%d\n", ans);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}