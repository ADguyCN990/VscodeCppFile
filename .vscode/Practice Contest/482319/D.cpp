#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
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

bool isvalid[MAXN][MAXN]; 
int dp[MAXN]; //[i,n]最小的切割数量
int n, k;
char s[MAXN];

void solve() {
    n = read(), k = read();
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            isvalid[i][j] = true;
    for (int i = 1; i <= n; i++) {
        isvalid[i][i] = false; //方便下面递推转移，后面在改回来
        for (int j = i + 1; j <= n; j++) {
            if (!isvalid[i][j - 1] && s[j] != s[j - 1])
                isvalid[i][j] = false;
            else
                break;
        }
        isvalid[i][i] = true;
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0] = -1;
    for (int i = 1; i <= n; i++) {
        for (int len = 1; len <= k; len++) {
            int j = i - len + 1;
            if (!j) break;
            if (isvalid[j][i])
                dp[i] = min(dp[j - 1] + 1, dp[i]);
        }
    }
    
    printf("%d\n", dp[n]);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}