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
void solve() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    vector<int> ans;
    if (n == 2) {
        puts("2");
        printf("%d %d\n", a[1], a[2]);
        return;
    }
    ans.pb(a[1]);
    for (int i = 2; i < n; i++) {
        if (a[i] - a[i - 1] >= 0 && a[i + 1] - a[i] >= 0 || a[i] - a[i - 1] < 0 && a[i + 1] - a[i] <= 0)
            continue;
        else
            ans.pb(a[i]);
    }
    ans.pb(a[n]);
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
    puts("");
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}