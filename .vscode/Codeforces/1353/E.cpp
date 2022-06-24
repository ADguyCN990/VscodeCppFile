#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
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
ll n, k;
char s[MAXN];
ll pre[MAXN];
ll zero[MAXN]; //第i位为0时，前面合法方案的最小变换数量
ll one[MAXN]; //第i位为1时，前面合法方案的最小变换数量
void solve() {
    n = read(), k = read();
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1];
        if (s[i] == '1')
            pre[i]++;
    }
    for (int i = 1; i <= n; i++) {
        zero[i] = min(zero[i - 1], one[i - 1]) + (ll)(s[i] == '1');
        if (i > k)
            one[i] = min(pre[i - 1], one[i - k] + pre[i - 1] - pre[i - k])  + (ll)(s[i] == '0');
        else
            one[i] = pre[i - 1] + (ll)(s[i] == '0');
    }
    printf("%lld\n", min(zero[n], one[n]));
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}