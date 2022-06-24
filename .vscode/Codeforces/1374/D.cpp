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
map<int, ll> mp;

void init() {
    mp.clear();
}

void solve() {
    n = read(), k = read();
    init();
    ll mx = 0, mxnum = 0; //最多的出现次数，最多的出现次数中数字最小的
    ll mn = INF; //最小的数字
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        ll num = a[i] % k;
        if (num == 0) continue; //本来就能整除，忽略
        mp[num]++;
        if (mp[num] > mx) {
            mx = mp[num];
            mxnum = num;
        }
        else if (mp[num] == mx) 
            if (num < mxnum) 
                mxnum = num;
        mn = min(mn, num);
    }
    if (mx == 0) {
        puts("0");
        return;
    }
    if (mx == 1) {
        printf("%lld\n", k - mn + 1);
        return;
    }
    printf("%lld\n", k * (mx - 1) + (k - mxnum) + 1);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}