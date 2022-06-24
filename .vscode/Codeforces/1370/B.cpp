#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 2005
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
void solve() {
    n = read();
    for (int i = 1; i <= n + n; i++) a[i] = read();
    vector<int> odd, even;
    for (int i = 1; i <= n + n; i++) {
        if (a[i] & 1)
            odd.pb(i);
        else
            even.pb(i);
    }
    vector<pii> ans;
    for (int i = 0; i + 1 < odd.size(); i += 2) {
        ans.pb(odd[i], odd[i + 1]);
    }
    for (int i = 0; i + 1 < even.size(); i += 2) {
        ans.pb(even[i], even[i + 1]);
    }
    for (int i = 0; i < n - 1; i ++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}