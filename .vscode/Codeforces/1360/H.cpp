#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
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
int n, m;
char s[MAXN];
ll a[MAXN], idx;
map<ll, int> vis; //标记是否已经被删除
ll stringToInt(char s[]) {
    ll ans = 0;
    reverse(s, s + m);
    for (int i = 0; i < m; i++) {
        int u = s[i] - '0';
        if (u)
            ans = ans  + (1ll << i);
    }
    return ans;
}

string intToString(ll x) {
    string ans = "";
    for (int i = m - 1; i >= 0; i--) {
        int u = x >> i & 1;
        ans += (char)('0' + u);
    }
    return ans;
}

void init() {
    idx = 0;
    vis.clear();
}

void solve() {
    n = read(), m = read();
    init();
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        a[++idx] = stringToInt(s);
    }
    sort(a + 1, a + 1 + idx);
    ll k = (1ll << m); //[0, k - 1],k表示个数
    ll mid = (k - 1) >> 1;
    for (int i = 1; i <= idx; i++) {
        vis[a[i]] = 1; //表示已经被删除
        ll del = a[i];
        if (k & 1 && del >= mid) {
            //左移
            while (vis[mid - 1]) mid--;
            mid = mid - 1;
        }
        if (k % 2 == 0 && del <= mid) {
            //右移
            while (vis[mid + 1]) mid++;
            mid = mid + 1;
        }
        k--;
    }
    cout << intToString(mid) << "\n";
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}