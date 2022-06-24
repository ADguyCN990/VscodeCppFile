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
int n, p;
int a[MAXN];
void solve() {
    n = read(), p = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, a[i]);
    }
    sort(a + 1, a + 1 + n);
    vector <int> ans;
    for (int i = 1; i <= mx; i++) {
        ll tmp = 1;
        int pos = 1;
        for (int j = 1; j <= n; j++) {
            while (pos <= n && i + j - 1 >= a[pos]) pos++;
            tmp *= (pos - j);
            tmp %= p;
        }
        if (tmp)
            ans.pb(i);
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
}

int main() {
    solve();
    return 0;
}