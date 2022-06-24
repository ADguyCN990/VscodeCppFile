#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 15
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
ll n, m, k, r; //n是课外题目，m是作业，k是及格线，r是剩余时间
ll extra[MAXN], v[MAXN], w[MAXN]; 
ll dp[200]; //定义状态：用i的时间能达到的最高分数/个数
void solve() {
    n = read(), m = read(), k = read(), r = read(); 
    //先求出最少需要用多少时间来达到及格线（大于等于k）
    for (int i = 1; i <= n; i++) extra[i] = read();
    for (int i = 1; i <= m; i++) v[i] = read();
    for (int i = 1; i <= m; i++) w[i] = read();
    for (int i = 1; i <= m; i++) 
        for (int j = r; j >= v[i]; j--) 
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    int V;
    for (int i = 1; i <= r; i++) {
        if (dp[i] >= k) {
            V = i;
            break;
        }
    }
    V = r - V; //做课外作业的时间
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i++) {
        for (int j = V; j >= extra[i]; j--) {
            dp[j] = max(dp[j], dp[j - extra[i]] + 1);
        }
    }
    printf("%lld\n", dp[V]);
}

int main() {
    solve();
    return 0;
}