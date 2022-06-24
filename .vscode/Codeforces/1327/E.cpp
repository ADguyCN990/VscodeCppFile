#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define mod 998244353
#define ll long long
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
//int cnt1, cnt2, cnt3, cnt4;
ll dp[MAXN];
ll lg[MAXN];
ll sum = 390, tmp = 190;
void solve() {
    ll n = read();
    lg[0] = 1;
    for (int i = 1; i <= n; i++) 
        lg[i] = lg[i - 1] * 10 % mod;
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i] * i % mod;
    dp[n] = 10, dp[n - 1] = 180;
    for (int i = n - 2; i >= 1; i--) {
        int now = n - i + 1;
        ll need = lg[now];
        dp[i] = (need - sum + mod) % mod;
        sum = (sum + dp[i] * 2 + tmp) % mod;
        tmp = (tmp + dp[i]) % mod;
    }
    for (int i = 1; i <= n; i++) printf("%lld ", dp[i]);
}

int main() {
    // for (int i = 0; i <= 9999; i++) {
    //     string s;
    //     if (i < 10)
    //         s = "000" + to_string(i);
    //     else if (i < 100)
    //         s = "00" + to_string(i);
    //     else if (i < 1000)
    //         s = "0" + to_string(i);
    //     else
    //         s = to_string(i);
    //     if (s[0] == s[1] && s[1] == s[2] && s[2] == s[3] )
    //         cnt4++;
    //     else if (s[0] == s[1] && s[1] == s[2] && s[2] != s[3] ||
    //              s[0] != s[1] && s[1] == s[2] && s[2] == s[3])
    //         cnt3++, cnt1++;
    //     else if (s[0] == s[1] && s[2] == s[3] && s[1] != s[2])
    //         cnt2 += 2;
    //     else if (s[0] == s[1] && s[2] != s[1] && s[3] != s[2] ||
    //              s[0] != s[1] && s[1] == s[2] && s[2] != s[3] ||
    //              s[0] != s[1] && s[1] != s[2] && s[2] == s[3])
    //         cnt1 += 2, cnt2 += 1;
    //     else
    //         cnt1 += 4;
    // }
    // printf("1: %d 2: %d 3:%d 4:%d\n", cnt1, cnt2, cnt3, cnt4);
    solve();
    return 0;
}