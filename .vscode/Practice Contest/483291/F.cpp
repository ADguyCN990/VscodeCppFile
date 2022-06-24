#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 8005
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
int n;
int decimal[MAXN]; //十进制数的位数
ll dp[MAXN]; //前i位压缩完最少的位数
int nxt[MAXN];

void kmp(int len, char *s) {
    nxt[0] = nxt[1] = 0;
    for (int i = 1; i < len; i++) {
        int j = nxt[i];
        while (j && s[i] != s[j]) j = nxt[j];
        if (s[j] == s[i])
            nxt[i + 1] = j + 1;
        else
            nxt[i + 1] = 0;
    }
}

void prework() {
    for (int i = 0; i < 10; i++) decimal[i] = 1;
    for (int i = 10; i < 100; i++) decimal[i] = 2;
    for (int i = 100; i < 1000; i++) decimal[i] = 3;
    for (int i = 1000; i <= 8000; i++) decimal[i] = 4;
    for (int i = 1; i <= n; i++) dp[i] = i + 1;
}

void solve() {
    scanf("%s", s);
    n = strlen(s);
    prework();
    for (int i = 0; i < n; i++) {
        kmp(n - i, s + i);
        for (int j = 1; j + i <= n; j++) {
            //j表示i和p之间的字符数量
            int len = j - nxt[j];
            if (j % len) {
                dp[j + i] = min(dp[j + i], dp[i] + 1 + j);
            }
            else {
                dp[j + i] = min(dp[j + i], dp[i] + decimal[j / len] + len);
            }
        }
    }
    printf("%d\n", dp[n]);
}

int main() {
    solve();
    return 0;
}