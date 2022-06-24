#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 3005
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
vector<int> num;
int findx(int x) {
    return lower_bound(num.begin(), num.end(), x) - num.begin() + 1;
}

void init() {
    num.clear();
}
void solve() {
    n = read();
    init();
    for (int i = 1; i <= n; i++) a[i] = read(), num.pb(a[i]);
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    for (int i = 1; i <= n; i++)
        a[i] = findx(a[i]);
    //寻找最长的公差为1的子序列
    int mx = 1;
    for (int i = 1; i <= n; i++) {
        int now = a[i];
        int len = 1;
        for (int j = i + 1; j <= n; j++) {
            if (a[j] - now == 1) {
                now++;
                len++;
            }
        }
        mx = max(mx, len);
    }
    printf("%d\n", n - mx);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}