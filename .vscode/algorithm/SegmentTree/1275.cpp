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
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int dp[MAXN][32]; //从i开始，长度为2^j的区间中的最大值
int n; //区间长度
int a[MAXN]; //存放序列
int lg[MAXN]; //每个数以2为底的对数 (highbit)
int m; //查询次数

void pre() //预处理出以2为底的对数
{
    ;
    for (int i = 1; i <= n; i ++) lg[i] = (int)(log2(i));
}

void init()
{
    for (int i = 1; i <= n; i ++) dp[i][0] = a[i];
    for (int j = 1; j <= lg[n]; j ++)
        for (int i = 1; i <= n; i ++)
            dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
}

void solve()
{
    n = read();
    for (int i = 1; i <= n; i ++) a[i] = read();
    pre();
    init();
    m = read();
    while (m --)
    {
        int l, r; //询问[l,r]这段区间的最大值
        l = read(), r = read();
        int k = lg[r - l + 1];
        printf("%d\n", max(dp[l][k], dp[r - (1 << k) + 1][k]));
    }
}

int main()
{
    solve();
    return 0;
}