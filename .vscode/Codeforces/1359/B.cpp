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
char s[MAXN][MAXN];
void solve() {
    int n, m, x, y;
    n = read(), m = read(), x = read(), y = read();
    for (int i = 1; i <= n; i++)
        scanf("%s", s[i] + 1);
    if (x * 2 <= y) {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (s[i][j] == '.')
                    cnt++;
        printf("%d\n", cnt * x);
    }
    else {
        int one = 0;
        int two = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i][j] == '.' && j + 1 <= m && s[i][j + 1] == '.') {
                    two++;
                    j++;
                }
                else if (s[i][j] == '.')
                    one++;
            }
        }
        printf("%d\n", one * x + two * y);
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