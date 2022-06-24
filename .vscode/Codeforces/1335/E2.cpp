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
vector<int> pos[205];
int sum[MAXN][205];
int n;
int a[MAXN];
void init() {
    for (int i = 1; i <= 200; i++) pos[i].clear();
}

void solve() {
    init();
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    if (n == 1) {
        puts("1");
        return;
    }
    if (n == 2) {
        if (a[1] == a[2])
            puts("2");
        else
            puts("1");
        return;
    }
    for (int i = 1; i <= 200; i++) pos[i].pb(0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 200; j++) {
            sum[i][j] = sum[i - 1][j];
            if (a[i] == j)
                sum[i][j]++;
        }
        pos[a[i]].pb(i);
    }
    for (int i = 1; i <= 200; i++) pos[i].pb(n + 1);
    int ans = 0;
    for (int i = 1; i <= 200; i++) {
        int cnt = pos[i].size() - 2;
        for (int j = cnt / 2; j >= 0; j--) {
            int ans1 = j * 2;
            int l = pos[i][j] + 1;
            int r = pos[i][cnt - j + 1] - 1;
            //printf("%d %d\n", l, r);
            int ans2 = 0;
            for (int k = 1; k <= 200; k++) {
                ans2 = max(ans2, sum[r][k] - sum[l - 1][k]);
            }
            ans = max(ans, ans1 + ans2);
        }
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