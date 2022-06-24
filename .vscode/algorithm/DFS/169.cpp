#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
int n;
int sum;
int a[MAXN];//小棍长度
int vis[MAXN];
int length;

bool dfs(int now,int len,int start)//正在枚举第now根大棍，长度为len，从第start根小棍开始找
{
    if((now-1)*length==sum) return true;
    if(len==length) return dfs(now+1,0,0);
    for(int i=start+1;i<=n;i++)
    {
        if(vis[i]) continue;
        if(len+a[i]>length) continue;//可行性剪枝

        vis[i]=1;
        if(len+a[i]<=length) 
            if(dfs(now,len+a[i],i))
                return true;
        vis[i]=0;//恢复现场

        //走到这说明第i根木棍失败了
        if(!len) return false; 

        if(len+a[i]==length) return false;

        int j=i;
        while(j<=n&&a[j]==a[i]) 
            j++;
        i=j-1;
    }
    //所有木棒试了遍依然不行
    return false;
}

bool cmp(int a,int b) {return a>b;}

void solve()
{
    memset(vis,0,sizeof vis);
    sum=0;
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        mx=max(mx,a[i]);
    }
    sort(a+1,a+1+n,cmp);
    for(int i=mx;i<=sum;i++)//大棍长度一定要大于等于所有小棍的最大值
    {
        if(sum%i) continue;
        length=i;
        if(dfs(1,0,0))
        {
            cout<<i<<endl;
            return;
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin>>n&&n)
    {
        solve();
    }
    return 0;
}