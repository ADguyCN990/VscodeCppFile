#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 2005
int n;
char mp[MAXN][MAXN];
//0~9
int l[15],r[15],u[15],d[15];
int ans[MAXN];//每个数字对应的面积
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%s",mp[i]+1);
    for(int i=0;i<=10;i++)
    {
        l[i]=0x3f3f3f3f;r[i]=-1;u[i]=0x3f3f3f3f;d[i]=-1;ans[i]=0;
    }
    //记录每个数字出现的最边缘的位置
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x=mp[i][j]-'0';
            l[x]=min(l[x],j);r[x]=max(r[x],j);
            u[x]=min(u[x],i);d[x]=max(d[x],i);
        }
    }
    //枚举平行边
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x=mp[i][j]-'0';
            ans[x]=max(ans[x],max(i-u[x],d[x]-i)*max(n-j,j-1));//改变第一列或者第n列
            ans[x]=max(ans[x],max(j-l[x],r[x]-j)*max(n-i,i-1));//改变第一行或者第n行
        }
    }
    for(int i=0;i<10;i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}