#include<bits/stdc++.h>
using namespace std;
#define MAXN 205
#define ll long long

ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
ll n;
ll b[MAXN];
ll a[MAXN];
bool vis[MAXN];
void solve() {
    n = read();
    memset(vis, false, sizeof vis);
    for (int i = 1; i <= n; i++) b[i] = read();
    for (int i = 1; i <= n; i++) {
        vis[b[i]] = true;
        if (b[i] == 2 * n) {
            puts("-1");
            return;
        }
    }
    for (int i = 1; i <= n; i++) {
        int now = b[i];
        a[i * 2 - 1] = now;
        //vis[now] = true; 
        bool flag = false;
        for (int j = now + 1; j <= 2 * n; j++) {
            if (!vis[j]) {
                vis[j] = true;
                a[i * 2] = j;
                flag = true;
                break;
            }
        }
        if (!flag) {
            puts("-1");
            return;
        }
    }
    for (int i = 1; i <= 2 * n; i++) printf("%d ", a[i]);
    puts("");
}

int main() {
    int t = read();
    while (t--)
        solve();
    return 0;
}
