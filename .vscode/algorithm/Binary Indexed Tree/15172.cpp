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

int c[MAXN][MAXN], a[MAXN][MAXN];
int n, m;

int lowbit(int x) {
    return x & -x;
}

void update(int x, int y, int val) {
    for (int i = x; i <= n; i += lowbit(i))
        for (int j = y; j <= n; j += lowbit(j))
            c[i][j] += val;
}

int ask(int x, int y) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i))
        for (int j = y; j; j -= lowbit(j))
            ans += c[i][j];
    return ans;
}


void solve() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = read();
            if (a[i][j])
                update(i, j, 1);
        }
    }
    while (m--) {
        int opt = read();
        if (opt == 1) {
            int x = read(), y = read();
            if (a[x][y] == 1) {
                a[x][y] = 0;
                update(x, y, -1);
            }
            else {
                a[x][y] = 1;
                update(x, y, 1);
            }
        }
        else if (opt == 2) {
            int x = read(), y = read(), xx = read(), yy = read();
            
            printf("%d\n", ask(xx, yy) - ask(xx, y - 1) - ask(x - 1, yy) + ask(x - 1, y - 1));
        }
    }
}

int main() {
    solve();
    return 0;
}