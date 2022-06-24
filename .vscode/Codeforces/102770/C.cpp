#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 4000005
int idx, son[MAXN][30];
int a[MAXN];
char g[1005][1005];
int n, m;
char tmps[1005];

void init() {
    for (int i = 0; i <= idx; i++) {
        memset(son[i], 0, sizeof son[i]);
        a[i] = 0;
    }
    idx = 0;
}

void insert(char s[], int len, int val) {
    int now = 0;
    for (int i = 1; i <= len; i++) {
        int u = s[i] - 'a'; 
        if (!son[now][u])
            son[now][u] = ++idx;
        now = son[now][u];
    }
    a[now] = val;
}

int query(char s[], int len) {
    int now = 0;
    for (int i = 1; i <= len; i++) {
        int u = s[i] - 'a';
        if (!son[now][u]) return -1;
        now = son[now][u];
    }
    if (a[now]) return a[now];
    else if (!a[now]) return -1;
}

void solve() {
    init();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s", g[i] + 1);
    for (int i = 1; i <= m; i++) {
        scanf("%s", tmps + 1);
        int val;
        scanf("%d", &val);
        int len = strlen(tmps + 1);
        insert(tmps, len, val);
    }
    
    //横向查询
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int len = 0;
            if (g[i][j] == '#') continue;
            while (j <= n && g[i][j] != '#') {
                tmps[++len] = g[i][j];
                j++;
            }
            tmps[len + 1] = '\0';
            //puts(tmps + 1);
            int tmp = query(tmps, len);
            if (tmp == -1) {
                puts("-1");
                return;
            }
            ans += tmp;
            //j--;
        }
    }

    //纵向查询
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int len = 0;
            if (g[j][i] == '#') continue;
            while (j <= n && g[j][i] != '#') {
                tmps[++len] = g[j][i];
                j++;
            }
            tmps[len + 1] = '\0';
            //puts(tmps + 1);
            int tmp = query(tmps, len);
            if (tmp == -1) {
                puts("-1");
                return;
            }
            ans += tmp;
            //j--;
        }
    }

    printf("%lld\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}