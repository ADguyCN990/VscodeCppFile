#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 10005
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
ll n, V;
ll v[MAXN], w[MAXN], s[MAXN];
ll dp[MAXM];

void solve() {
    ll ah, am, bh, bm;
    scanf("%lld:%lld %lld:%lld", &ah, &am, &bh, &bm);
    n = read();
    ll V = bh * 60 + bm - ah * 60 - am;
    for (int i = 1; i <= n; i++) {
        v[i] = read();
        w[i] = read();
        s[i] = read();
    }
    for (int i = 1; i <= n; i++) {
        if (!s[i])  //完全背包
            for (int j = v[i]; j <= V; j++)
                dp[j] = max(dp[j - v[i]] + w[i], dp[j]);
        else { //多重背包，二进制拆分
            for (int k = 1; k <= s[i]; k *= 2) {
                for (int j = V; j >= k * v[i]; j--)
                    dp[j] = max(dp[j], dp[j - k * v[i]] + k * w[i]);
                s[i] -= k;
            }
            if (s[i]) 
                for (int j = V; j >= s[i] * v[i]; j--)
                    dp[j] = max(dp[j], dp[j - s[i] * v[i]] + s[i] * w[i]); 
            
        }
        
    }
    printf("%lld\n", dp[V]);
}

int main() {
    solve();
    return 0;
}