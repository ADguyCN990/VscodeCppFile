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
#define gcd(x, y) __gcd(x, y)
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int n;
ll a[MAXN];

int highbit(int n)
{
    for (int i = 31; i >= 0; i --)
    {
        int u = n >> i & 1;
        if(u) return i;
    }
}
int have1[MAXN], have2[MAXN];
void solve()
{
    n = read();
    rep (i, 0, n - 1) a[i] = read();
    sort(a, a + n);
    int k = highbit(n); //最高位1的位置
    for (int i = 0; i <= k; i ++) //为了让lightfat的人数达到 (2^i) 个，前面一部分的人最多能有几个
    {
        int have = 0;
        while (have < (1 << i) && a[have] < a[1 << i]) have ++;
        have1[i] = have;
    }
    reverse(a, a + n);
    for (int i = 0; i <= k; i ++) //为了让overfat的人数达到 (2^i) 个，后面一部分的人最多能有几个
    {
        int have = 0;
        while (have < (1 << i) && a[have] > a[1 << i]) have ++;
        have2[i] = have;
    }
    int ans = INF;
    for (int i = 0; i <= k; i ++)
    {
        for (int j = 0; j <= k; j ++)
        {
            int mid_cnt = max(1, n - have1[i] - have2[j]); //n减去前面拿走的减去后面拿走的就是中间的部分
            int kk = highbit(mid_cnt);
            if(mid_cnt != (1 << kk))
                mid_cnt = 1 << (kk + 1);
            ans = min(ans, (1 << i) + (1 << j) + mid_cnt - n);
        }
    }
    printf("%d\n", ans);
}

int main()
{
    int T;
    T = read();
    while (T --)
    {
        solve();
    }

    return 0;
}