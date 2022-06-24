#include<bits/stdc++.h>
using namespace std;
#define MAXN 505
int num[MAXN][MAXN]; //记录区间内容
int dp[MAXN][MAXN]; //记录区间数字个数
int n, a[MAXN];
int read() {
    int x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    memset(dp, 0x3f, sizeof dp);
    for (int len = 1; len <= n; len++) {
        for (int l = 1, r; r = l + len - 1, r <= n; l++) {
            if (len == 1) {
                dp[l][r] = 1;
                num[l][r] = a[l];
            }
            else {
                for (int k = l; k < r; k++) {
                    //[l, k] [k + 1, r]
                    if (dp[l][k] == 1 && dp[k + 1][r] == 1 && num[l][k] == num[k + 1][r]) {
                        dp[l][r] = 1;
                        num[l][r] = num[l][k] + 1;
                    }
                    else {
                        dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
                    }
                }
                //printf("l: %d r: %d num: %d\n", l, r, num[l][r]);
            }
        }
    }
    printf("%d\n", dp[1][n]);
    return 0;
}