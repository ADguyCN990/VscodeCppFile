#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
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
vector<int> pos[30];
int n, m;
char s[MAXN], t[MAXN];

void init() {
    for (int i = 0; i < 26; i++) pos[i].clear();
}

void solve() {
    n = read(), m = read();
    init();
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    for (int i = 1; i <= n; i++) {
        int u = s[i] - 'a';
        pos[u].pb(i);
    }
    int ans = 0;
    while (1) {
        bool flag = true;
        int now = n + 1;
        for (int i = m; i > 0; i--) {
            int u = t[i] - 'a';
            while (pos[u].size() && pos[u].back() >= now)
                pos[u].pop_back();
            if (pos[u].empty()) {
                flag = false;
                break;
            }
            now = pos[u].back();
            pos[u].pop_back();
        }
        if (flag)
            ans ++;
        else
            break;
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