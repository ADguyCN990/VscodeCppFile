#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

vector<int> g[MAXN];
int n, k, cnt;
bool vis[MAXN];

void init() {
    for (int i = 1; i <= n; i++) {
        vis[i] = false;
        g[i].clear();
    }
    cnt = 0;
}

void solve() {
    n = read();
    init();
    vector<int> wa;
    for (int i = 1; i <= n; i++) {
        k = read();
        for (int j = 1; j <= k; j++) {
            int tmp = read();
            g[i].push_back(tmp);
        }
        bool flag = false;
        for (int j = 0; j < k; j++) {
            if (!vis[g[i][j]]) {
                vis[g[i][j]] = true;
                flag = true;
                cnt++;
                break;
            }
        }
        if (!flag)
            wa.push_back(i);
    }
    int len = wa.size();
    if (!len) {
        puts("OPTIMAL");
        return;
    }
    puts("IMPROVE");
    int id;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            id = i;
            break;
        }
    }
    printf("%d %d\n", wa[0], id);
}

int main() {
    int T = read();
    while (T--)
        solve();
    return 0;
}