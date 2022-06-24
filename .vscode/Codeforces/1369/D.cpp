#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 2000005
#define MAXM 200005
#define mod 1000000007
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
ll n;
bool add[MAXN];
ll dp[MAXN];

void pre() {
    add[1] = add[2] = false;
    dp[1] = dp[2] = 0;
    for (int i = 3; i <= 2000000; i++) {
        dp[i] = (2 * dp[i - 2] + dp[i - 1]) % mod;
        if (!add[i - 2] && !add[i - 1]) {
            dp[i] ++;
            add[i] = true;
        }
        else
            add[i] = false;
    }
}

void solve() {
    n = read();
    printf("%lld\n", 4 * dp[n] % mod); 
}

int main() {
    int T;
    pre();
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}