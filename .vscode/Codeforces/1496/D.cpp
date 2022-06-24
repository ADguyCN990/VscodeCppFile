#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define ll long long
ll n;
ll a[MAXN];
int max_l=0;
int min_l=0;
int cnt=0;
int dp[MAXN][2];//0表示递增，1表示递减
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        dp[i][0]=1;dp[i][1]=1;
    }
    for(int i=2;i<=n;i++)
    {
        if(a[i]>a[i-1]) dp[i][0]=dp[i-1][0]+1;
    }
    for(int i=n-1;i>0;i--)
    {
        if(a[i]>a[i+1]) dp[i][1]=dp[i+1][1]+1;
    }
    for(int i=1;i<=n;i++)
    {
        if(i!=n&&(dp[i][0]==1||dp[i][1]==1)&&i!=1) continue;//排除是波峰的情况
        int mx=max(dp[i][0],dp[i][1]);
        int mm=min(dp[i][0],dp[i][1]);
        if(mx>max_l)
        {
            max_l=mx;cnt=1;min_l=mm;
        }
        else if(mx==max_l)
        {
            cnt++;
        }
    }

    if(cnt>=2||max_l%2==0||(max_l%2==1&&max_l!=min_l)) cout<<0<<endl;
    else  cout<<1<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}