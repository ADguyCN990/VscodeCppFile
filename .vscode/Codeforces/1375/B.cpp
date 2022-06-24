#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
#define ll long long
#define MAXN 305
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
int n, m;
ll a[MAXN][MAXN];

bool check() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1 || i == 1 && j == m || i == n && j == 1 || i == n && j == m) {
                //printf("1: %d %d\n", i, j);
                if (a[i][j] > 2)
                    return false;
            }
                
            else if (i == 1 || i == n || j == 1 || j == m) {
                //printf("2: %d %d\n", i, j);
                if (a[i][j] > 3)
                    return false;
            }
                
            else if (i > 1 && i < n && j > 1 && j < m) {
                //printf("3: %d %d\n", i, j);
                if (a[i][j] > 4)
                    return false;
            }
                
        }
    }
    return true;
}

void solve() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = read();
    bool flag = check();
    if (!flag) {
        puts("NO");
        return;
    }
    puts("YES");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1 || i == 1 && j == m  || i == n && j == 1 || i == n && j == m) 
                printf("2 ");
            else if (i == 1 || i == n || j == 1 || j == m)
                printf("3 ");
            else
                printf("4 ");
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