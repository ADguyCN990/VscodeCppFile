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
string s[MAXN];
int n, k;
map<string, int> mp;
int cnt = 0;
int vis[MAXN];
struct node {
    int pos;
    int id;
    friend bool operator< (node a, node b) {
        if (a.id == b.id)
            return a.pos < b.pos;
        return a.id < b.id;
    }
}a[MAXN];

void solve() {
    n = read(), k = read();
    for (int i = 1; i <= n; i++) {
        string tmp;
        cin >> tmp;
        if (!mp.count(tmp)) {
            cnt++;
            mp[tmp] = cnt;
        }
        int id = mp[tmp];
        vis[id]++;
        a[i].id = id, a[i].pos = i;
    }
    sort(a + 1, a + 1 + n);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int j = i + vis[a[i].id] - 1;
        ll l = i, r = i + 1;
        while (l <= r && r <= j) {
            while (l <= r && r <= j && a[r].pos - a[l].pos - 1 <= k) {
                ans += r - l;
                r++;
            }
            l++;

        }
        i += vis[a[i].id] - 1;
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}