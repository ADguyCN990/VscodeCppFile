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
int vis[20005];
int tmp[20005];
int n, x;
void solve() {
    n = read(), x = read();
    vis[0] = 1;
    for (int i = 1; i <= n; i++) {
        int a = read(), b = read();
        memset(tmp, 0, sizeof tmp);
        for (int i = 0; i <= 10000; i++) {
            if (vis[i]) {
                tmp[i + a] = 1;
                tmp[i + b] = 1;
            }
        }
        memcpy(vis, tmp, sizeof vis);
    }
    if (vis[x])
        puts("Yes");
    else
        puts("No");
}

int main() {
    solve();
    return 0;
}