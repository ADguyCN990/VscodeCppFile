#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 5005
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
int g[MAXN][MAXN];
int n, m, k;
int cnt[MAXN];
void work(int x, int y, int z) {
    //(x, y)
    for (int i = 1; i <= n; i++) g[i][y] = z;
    for (int i = 1; i <= m; i++) g[x][i] = z;
}

void solve() {
    n = read(), m = read(), k = read();
    for (int i = 1; i <= k; i++) {
        int x = read(), y = read(), z = read();
        work(x, y, z);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cnt[g[i][j]]++;
    int mx = 0;
    int id;
    for (int i = 1; i <= 5000; i++) {
        if (cnt[i] > mx) {
            mx = cnt[i];
            id = i;
        }
    }
    printf("%d %d\n", mx, id);
        
}

int main() {
    solve();
    return 0;
}