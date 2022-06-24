#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 5005
ll dp[MAXN][MAXN];//表示为前i次选择选了j次第三类，选了i-j次第一类和第二类
struct node
{
    ll a;
    ll b;
    ll c;
}card[MAXN];
ll n,a,b,c;
bool cmp(node a,node b)//排序后优先选b，因为b大的都被移到了前面
{
    if(a.b-a.a==b.b-b.a) return a.c>b.c;
    return a.b-a.a>b.b-b.a;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>a>>b>>c;
    for(int i=1;i<=n;i++)
    {
        cin>>card[i].a>>card[i].b>>card[i].c;
    }
    for(int i=0;i<=n;i++)//dp[i-1][j] 会导致i<j的情况，必须初始化为无穷小（让它够小到无法更新dp[i][j]的值，因为这种i<j的情况是非法的，不可能存在的）
    {
        for(int j=i+1;j<=c;j++) 
        {
            dp[i][j]=-1e9;
        }
    }
    sort(card+1,card+1+n,cmp);
    for(int i=1;i<=n;i++)//第i个物品
    {
        for(int j=0;j<=min(i,(int)c);j++)//选了j个第三类物品
        {
            if(j>0) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+card[i].c);//选C
            if(i-j<=b) dp[i][j]=max(dp[i][j],dp[i-1][j]+card[i].b);//b还能继续更新
            else dp[i][j]=max(dp[i][j],dp[i-1][j]+card[i].a);
        }
    }
    cout<<dp[n][c]<<endl;
    return 0;
}