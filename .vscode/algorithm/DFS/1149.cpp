#include<bits/stdc++.h>
using namespace std;
#define ll long long
int num[1005];//用火柴棍拼成数字i需要的数目
int n;
int ans=0;
int a[4];
void pre()
{
    num[0]=6;
    num[1]=2,num[2]=5,num[3]=5,num[4]=4,num[5]=5,num[6]=6,num[7]=3,num[8]=7,num[9]=6;
    for(int i=10;i<=999;i++)
    {
        num[i]=num[i/10]+num[i%10];
    }

}

void dfs(int now,int tot)
{
    if(now==4)
    {
        if(tot==0&&a[1]+a[2]==a[3]) ans++;
        return;
    }

    for(int i=999;i>=0;i--)
    {
        if(tot-num[i]>=0)
        {
            a[now]=i;
            dfs(now+1,tot-num[i]);
            a[now]=0;
        }
    }
}

void solve()
{
    pre();//将所有数字需要的火柴数表示出来
    cin>>n;
    dfs(1,n-4);
    cout<<ans<<endl;
}


int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}