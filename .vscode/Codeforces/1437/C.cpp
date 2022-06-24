#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 205
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
ll a[MAXN];
ll dp[1005][MAXN];//前i秒拿了j道菜的不愉悦值
int n;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=0;i<=1000;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            dp[i][j]=INF;
        }
    }
    for(int i=0;i<=1000;i++)
        dp[i][0]=0;
    for(int i=1;i<=1000;i++)
    {
        for(int j=1;j<=min(i,n);j++)
        {
            dp[i][j]=min(dp[i-1][j],dp[i-1][j-1]+abs(a[j]-i));
        }
    }
    cout<<dp[1000][n]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }

    return 0;
}