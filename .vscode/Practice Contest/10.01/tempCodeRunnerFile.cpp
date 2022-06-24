#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 5005
#define mod 998244353
ll n;
ll a[MAXN];
vector <ll> v;
ll cnt[MAXN];
ll order[MAXN];//预处理阶乘，最后要乘上顺序
ll dp[MAXN][MAXN];//dp[i][j]表示一共i个人，第一排放了j个人，第二排放了i-j个人的方案数量
void pre()
{
    order[0]=1;
    for(int i=1;i<=5000;i++) order[i]=order[i-1]*i%mod;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    pre();
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    sort(a+1,a+1+n);//排序后每次都先往第一排放，再往第二排放，一直保证第一排的人数不比第二排少，这样就可以完美避开题目的限制条件（因为后加的肯定比先加的高）
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]>0) v.emplace_back(cnt[i]);
    }
    dp[0][0]=1;//初始状态
    ll now=0;//目前已经处理过的人，相当于i
    for(int i=0;i<v.size();i++)
    {
        ll x=v[i];//身高这么高的有x个人，缩点
        now+=x;
        for(int j=min(now,n/2);j>=now-j;j--)//第一排的人数，取min是因为j不能超过一半,j>=now-j就能保证第一排的人不比第二排的人少
        {
            for(int k=0;k<=x&&k<=j;k++)//分配给了第一排k个人
            {
                dp[now][j]=(dp[now][j]+dp[now-x][j-k])%mod;//状态转移方程，累加上一次第一排人数为j-k的情况
            }
        }

    }
    ll ans=dp[n][n/2];//这个结果只是组合的情况种数，由于身高相同的人可以随意站位，还要乘上顺序（阶乘）
    for(int i=1;i<=n;i++)
    {
        ans=(ans*order[cnt[i]])%mod;
    }
    cout<<ans<<endl;
    return 0;
}