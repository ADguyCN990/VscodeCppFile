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
    a[n + 1] = 0;
    int flag;
    if (a[1] > 0)  
        flag = 1;
    else
        flag = -1;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int j = i;
        vector<ll> tmp;
        if (flag == 1) {
            while (a[j] > 0) {
                tmp.pb(a[j]);
                j++;
            }
            i = j - 1;
            flag = -1;
            sort(tmp.begin(), tmp.end(), greater<>());
            ans += tmp[0];
        }
        else {
            while (a[j] < 0) {
                tmp.pb(a[j]);
                j++;
            }
            i = j - 1;
            flag = 1;
            sort(tmp.begin(), tmp.end(), greater<>());
            ans += tmp[0];
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}