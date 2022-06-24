#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 55
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
int n, m, a, b;
int mp[MAXN][MAXN];
void solve() {
    n = read(), m = read(), a = read(), b = read();
    //每行a个1，每列b个1
    memset(mp, 0, sizeof mp);
    if (a * n != b * m) {
        puts("NO");
        return;
    }
    puts("YES");
    int now = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= a; j++) {
            if (now == m + 1) now = 1;
            mp[i][now] = 1;
            now++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d", mp[i][j]);
        }
        puts("");
    }
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}