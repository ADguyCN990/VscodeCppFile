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
int n;
int a[MAXN];
int id[15];
int p[MAXN], cnt, idx;
bool st[MAXN];
int mp[MAXN];
void Euler() {
    for (int i = 2; i <= 1000; ++i) {
        if (!st[i])
            p[++cnt] = i;
        for (int j = 1; p[j] <= 1000 / i; ++j) {
            st[p[j] * i] = true;
            if (i % p[j] == 0)
                break;
        }
    }
}

void solve() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    memset(mp, 0, sizeof mp);
    memset(id, 0, sizeof id);
    idx = 0;
    for (int i = 1; i <= n; i++) {
        bool flag = false;
        int tmp = -1;
        for (int j = 1; j <= cnt; j++) {
            if (a[i] % p[j] == 0) {
                if (mp[p[j]]) {
                    flag = true;
                    id[i] = mp[p[j]];
                    break;
                }
                if (!mp[p[j]]) {
                    if (tmp == -1) {
                        tmp = p[j];
                    }
                }
            }
        }
        if (!flag) {
            mp[tmp] = ++idx;
            id[i] = idx;
        }
    }
    printf("%d\n", idx);
    for (int i = 1; i <= n; i++) printf("%d ", id[i]);
}

int main() {
    Euler();
    
    int T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}