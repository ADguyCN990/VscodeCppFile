#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 5005
ll n;
ll a[MAXN];
ll dp[MAXN][MAXN];//前i个人坐在了前j个位置上
void solve()
{
    cin>>n;
    memset(dp,0x3f3f3f3f,sizeof(dp));
    for(int i=0;i<=n;i++) dp[0][i]=0;
    vector <int> pos_0;vector <int> pos_1;
    int len0,len1;
    for(int i=1;i<=n;i++) //把一开始数组为1的部分全部变成0
    {
        cin>>a[i];
        if(a[i]==1) pos_1.emplace_back(i);
        if(a[i]==0) pos_0.emplace_back(i);
    }
    len0=pos_0.size();len1=pos_1.size();
    for(int i=1;i<=len1;i++)
    {
        for(int j=i;j<=len0;j++)
        {
            dp[i][j]=min(dp[i][j-1],dp[i-1][j-1]+abs(pos_1[i-1]-pos_0[j-1]));
        }
    }
    cout<<dp[len1][len0]<<endl;

}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //int T;
    //cin>>T;
    //while(T--)
    //{
        solve();
    //}
    return 0;
}