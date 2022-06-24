#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 100005
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
int dp[MAXM];
int v[MAXN];
int n, V;
void solve() {
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    V = read();
    for (int i = 1; i * i * i * i <= V; i++) {
        n = i;
        v[i] = i * i * i * i;
    }    
    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j <= V; j++)
            dp[j] = min(dp[j], dp[j - v[i]] + 1);
    printf("%d\n", dp[V]);
}

int main() {
    solve();
    return 0;
}