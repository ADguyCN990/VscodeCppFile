#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll dp[80];//预处理好斐波那契数
int ans[105];

bool dfs(ll now,ll cnt,ll num)//尚未分解的数，分解的总个数，枚举到了第num个斐波那契数
{
    if(now==1)//所有数都分解完了
    {
        //cout<<cnt<<endl;
        for(int i=1;i<cnt;i++)//最后一位的1不能算进去
        {
            for(int j=1;j<=ans[i];j++)//某段的方案数有dp[i]个，就要输出i-2个'A',是i-2而非i是因为这题的斐波那契从dp[3]开始算起
            {
                cout<<"A";
            }
            cout<<"B";
        }
        return true;
    }
    for(ll i=num;i>2;i--)
    {
        if(now%dp[i]==0)
        {
            ans[cnt]=i-2;
            if(dfs(now/dp[i],cnt+1,i))
                return true;
        }
    }

    return false;
}

void pre()
{
    dp[1]=1;
    dp[2]=1;
    for(int i=3;i<=75;i++)
        dp[i]=dp[i-1]+dp[i-2];
    
}

void solve()
{   
    pre();
    cin>>n;
    bool flag=dfs(n,1,75);
    if(!flag) cout<<"IMPOSSIBLE"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}