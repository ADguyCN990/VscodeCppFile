#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 55
#define MAXM 1005
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
ll n, bg, V;
bool dp[2][MAXM];
ll c[MAXN];
void solve() {
    n = read(), bg = read(), V = read();
    for (int i = 1; i <= n; i++) c[i] = read();
    dp[0][bg] = true;
    for (int i = 1; i <= n; i++) {
        int now = i & 1;
        int pre = (i - 1) & 1;
        for (int j = 0; j <= V; j++) dp[now][j] = false;
        for (int j = 0; j <= V; j++) {
            if (dp[pre][j] && j - c[i] >= 0)
                dp[now][j - c[i]] = true;
            if (dp[pre][j] && j + c[i] <= V)
                dp[now][j + c[i]] = true;
        }
    }
    int now = n & 1;
    for (int j = V; j >= 0; j--) {
        if (dp[now][j]) {
            printf("%d\n", j);
            return;
        }
    }
    puts("-1");
}

int main() {
    solve();
    return 0;
}