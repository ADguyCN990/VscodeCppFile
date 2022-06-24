#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
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
pii a[MAXN], c[MAXN];
map <int, int> cnt;
int b[MAXN];
int n;
void solve() {
    n = read();
    for (int i = 1; i <= n; i++) {
        int tmp = read();
        a[i].first = tmp;
        a[i].second = ++cnt[tmp];
        c[i] = a[i];
    }
    sort(c + 1, c + 1 + n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (c[i] == a[j])
                b[i] = j;
    vector <pii> ans;
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j < i; j++) {
            if (b[j] > b[j + 1]) {
                swap(b[j], b[j + 1]);
                ans.pb(make_pair(b[j], b[j + 1]));
            }
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++)
        printf("%d %d\n", ans[i].first, ans[i].second);
}

int main() {
    solve();
    return 0;
}