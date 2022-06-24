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
char s[MAXN];
ll n;

int r[MAXN], d[MAXN]; //包括自身，在其之后还有多少个向下和向右的指令

void solve() {
    n = read();
    scanf("%s", s + 1);
    int m = strlen(s + 1);
    s[m + 1] == '#'; //哨兵
    int cntd = 0, cntr = 0;
    for (int i = m; i >= 1; i--) {
        if (s[i] == 'D')
            cntd++;
        if (s[i] == 'R')
            cntr++;
        r[i] = cntr, d[i] = cntd;
    }
    int x = 1, y = 1;
    ll ans = n * n;
    int waste = n - 1;
    for (int i = 1; i <= m; i++) {
        if (s[i] == 'D') {
            if (s[i + 1] == 'D')
                ans -= waste;
            else {
                ans -= waste;
                //由向下走变成像右走，浪费的东西变成了竖直方向
                if (i != m)
                    waste = max(0, d[i] - 1);
            }
            if (i != m)
                y++;
        }
        else if (s[i] == 'R') {
            if (s[i + 1] == 'R')
                ans -= waste;
            else {
                ans -= waste;
                //由向右走变成向下走，浪费的东西变成了水平方向
                if (i != m)
                    waste = max(0, r[i] - 1);
            }
            if (i != m)
                x++;
        }
    }
    if (s[m] == 'R')
        ans -= (n - x) * waste;
    else
        ans -= (n - y) * waste;
    printf("%lld\n", ans);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}