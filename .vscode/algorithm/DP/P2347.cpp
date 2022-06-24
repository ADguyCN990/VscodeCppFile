#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
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
ll v[10], cnt[10];
bool dp[2][MAXM];

void solve() {
    v[1] = 1, v[2] = 2, v[3] = 3, v[4] = 5, v[5] = 10, v[6] = 20;
    for (int i = 1; i <= 6; i++) cnt[i] = read();
    int now = 0;
    int pre;
    dp[0][0] = true;
    for (int i = 1; i <= 6; i++) {
        for (int k = 1; k <= cnt[i]; k++) {
            now = now ^ 1;
            pre = 1 - now;
            for (int j = 0; j <= 1000; j++)
                dp[now][j] = false;
            for (int j = 0; j <= 1000; j++) {
                if (dp[pre][j]) {
                    dp[now][j] = true;
                    if (j + v[i] <= 1000)
                        dp[now][j + v[i]] = true;
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= 1000; i++)
        if (dp[now][i])
            cnt++;
    printf("Total=%d\n", cnt);
}

int main() {
    solve();
    return 0;
}