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
ll n, k;
ll a[MAXN];
ll sum[MAXN];
ll ans;
bool flag1 = false, flag2 = false;

void solve()
{
    n = read(), k = read();
    for (int i = 1; i <= n; i ++) 
        a[i] = read();
    // if(flag1 && flag2)
    // {
    //     printf("%d %d\n", n, k);
    //     for (int i = 1; i <= n; i ++)
    //         printf ("%lld ", a[i]);
    //     puts("");
    //     return;
    // }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i ++)
        sum[i] = sum[i - 1] + a[i];
    if (sum[n] <= k)
    {
        puts("0");
        return;
    }
    if (n == 1)
    {
        printf("%lld\n", a[1] - k);
        return; 
    }
    ans = INF;
    //枚举变化的区间长度
    for (int i = 1; i <= n; i ++)
    {
        int r = n - i + 1;
        ll sum1 = sum[r] - sum[1];
        double sum2 = k - sum1;
        //剩下的部分的和要小于等于sum2
       // printf("sum2: %lf\n",sum2);
        ll mn = floor(sum2 / i);
        mn = min(mn, a[1]);
        ll opt = a[1] - mn + i - 1;
       //  printf("mn: %lld opt: %lld\n", mn, opt);
        ans = min(ans, opt);
    }

    printf("%lld\n", ans);
}

int main()
{
    int T;
    T=read();
    if (T == 6930)
        flag1 = true;
    for (int cnt = 1; cnt <= T; cnt ++)
    {
        flag2 = false;
        if(cnt == 35) flag2 = true;
        solve();
    }

    return 0;
}