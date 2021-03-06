#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define pb emplace_back
#define mod 998244353
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

int rt(int x)
{
    int u = x % 9;
    if (u == 0) u = 9;
    return u;
}

int n;
int a[MAXN];
ll dp[MAXN][15]; //èèäºåðä¸ªæ°ï¼éæ©äºä¸äºæ°å­ä½¿å¾æ±åå¯¹9åæ¨¡å¾ðçæ¹æ¡æ°


void solve()
{
    n = read();
    for (int i = 1; i <= n; i ++) a[i] = read(), a[i] = rt(a[i]);
    for (int i = 1; i <= n; i ++)
    {
        int now = a[i];
        for (int j = 1; j <= 9; j ++)
        {
            int to = rt(now + j);
            // å½åä½ç½®ä¸çæ°å­ä¸ºnowï¼æä¸¾1å°9ï¼å¯¹åºè½è¾¾å°çç¶æå°±æ¯ rt(now + j) 
            dp[i][to] = (dp[i - 1][to] + dp[i - 1][j]) % mod;
        }
        dp[i][now] ++; // ä¸è¦å¿è®°åç¬çè´¡ç®
    }
    for (int i = 1; i <= 9; i ++) printf("%lld ", dp[n][i]);
}

int main()
{
    solve();
    return 0;
}