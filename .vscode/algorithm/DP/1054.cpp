#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
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
char s[MAXN]; //模式串
int n;
int nxt[MAXN];
ll dp[MAXN][MAXN];
void solve() {
    n = read();
    scanf("%s", s + 1);
    int m = strlen(s + 1);
    for (int i = 2, j = 0; i <= m; i++) { //求kmp的next数组
        while (j && s[i] != s[j + 1]) j = nxt[j];
        if (s[i] == s[j + 1]) j++;
        nxt[i] = j;
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { //枚举匹配的最大后缀
            for (char ch = 'a'; ch <= 'z'; ch++) {
                int len = j; //计算枚举到第i+1个字符后，后缀匹配的最大长度
                while (len && s[len + 1] != ch) len = nxt[len];
                if (s[len + 1] == ch) len++; //能够匹配上
                if (!len) //第i+1为ch时，不能匹配上
                    dp[i + 1][0] = (dp[i + 1][0] + dp[i][j]) % mod;
                else //第i+1为ch时，能够匹配上，那么最大长度加1
                    dp[i + 1][len] = (dp[i + 1][len] + dp[i][j]) % mod;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < m; i++) ans = (ans + dp[n][i]) % mod;
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}