#include<bits/stdc++.h>
using namespace std;
#define MAXN 505
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
int read() {
    int x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

struct node {
    int e, ee, t, tt;
    friend bool operator< (node a, node b) {
        return a.e < b.e;
    }
}a[MAXN];
int n, V1, V2;
ll dp[2][MAXN][MAXN];

int main() {
    n = read(), V1 = read(), V2 = read();
    for (int i = 1; i <= n; i++) {
        a[i].e = read(), a[i].t = read(), a[i].ee = read(), a[i].tt = read();
    }
    sort(a + 1, a + 1 + n);
    for (int i = 0; i <= V1; i++)
        for (int j = 0; j <= V2; j++)
            dp[0][i][j] = INF;
    dp[0][0][0] = 0ll;
    for (int i = 1; i <= n; i++) {
        int now = i & 1;
        int pre = 1 - now;

        for (int j = V1; j >= 0; j--) {
            for (int k = V2; k >= 0; k--) {
                
                //从dp[pre][j][k] 转移到某个状态，首先这个状态得存在
                dp[now][j][k] = dp[pre][j][k];
                if (dp[now][j][k] >= INF) continue;
                int toj, tok;

                if (j < V1) {
                    //一周目副本状态转移
                    toj = a[i].e + j, tok = k;
                    if (toj > V1) { //经验溢出，继承到二周目 
                        tok = min(V2, tok + toj - V1);
                        toj = V1;
                    }
                    dp[now][toj][tok] = min(dp[now][toj][tok], dp[pre][j][k] + a[i].t);
                    
                }
                
                //二周目副本状态转移
                toj = j, tok = min(V2, k + a[i].ee);
                dp[now][toj][tok] = min(dp[now][toj][tok], dp[pre][j][k] + a[i].tt);

            }
        }
    }
    if (dp[n & 1][V1][V2] >= INF) 
        puts("-1");
    else
        printf("%lld\n", dp[n & 1][V1][V2]);    
    return 0;
}