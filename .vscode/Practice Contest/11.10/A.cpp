#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define ll long long
#define INF 0x3f3f3f3f
ll n, k, q;
ll a[MAXN];
ll dp[MAXN];
void solve()
{
    cin >> n >> q;
    double mx = -1; //性价比(体积尽可能大，释放的能量尽可能小)
    ll best;        //最高性价品物品的体积
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        double tmp = (i + 0.0) / (double)(a[i]);
        if (tmp > mx)
        {
            mx = tmp;
            best = i;
        }
    }
    memset(dp, INF, sizeof(dp));
    //处理最后一次分裂的结果
    for (int i = n + 1; i <= 2 * n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i - j <= n) //底层预留空间
            {
                dp[i] = min(dp[i], a[i - j] + a[j]);
            }
        }
    }
    //保证预留给最后一次分裂一定的空间，对剩下的部分进行多重背包
    for (int i = n + 1; i <= n * (n + 1); i++)
    {
        for (int j = 1; j <= n; j++)//体积
        {
            if (i - j > n)//剩余的还能再分裂，不会爆炸
            {
                dp[i] = min(dp[i], dp[i - j] + a[j]);
            }
        }
    }

    while(q--)
    {
        cin>>k;
        if(k<=n)
        {
            cout<<a[k]<<endl;
            continue;
        }
        else
        {
            if(k>n*(n+1))//可以贪心
            {
                ll cnt=(k-n*(best+1)+best-1)/best;//贪心的次数
                ll ans=cnt*a[best]+dp[k-cnt*best];//答案就是贪心的部分加上背包处理的部分
                cout<<ans<<endl;
            }
            else//数据较小不能贪心，直接背包
            {
                cout<<dp[k]<<endl;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}