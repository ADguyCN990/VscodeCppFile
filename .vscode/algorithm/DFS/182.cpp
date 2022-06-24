#include<bits/stdc++.h>
using namespace std;
#define MAXN 20
int n;
int a[MAXN];
int tmp[10][MAXN];//每层深度都要开一个以免互相影响

bool check()//判断是否升序
{
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(a[i]!=i)
            return false;
    return true;
}

int f()//估价函数，当前最少需要操作几次才能使序列升序
{
    int cnt=0;
    for(int i=2;i<=n;i++)
        if(a[i]!=a[i-1]+1)
            cnt++;
    return (cnt+2)/3;
}

bool dfs(int now,int mx)
{
    if(now+f()>mx) return false;//可行性剪枝，加上最少的步数依然无法有序,正常的版本f()代表的就是0
    if(check()) return true;

    for(int len=1;len<n;len++)
    {
        for(int i=1;i<=n;i++)
        {
            int j=i+len-1;
            if(j>=n) break;
            for(int k=j+1;k<=n;k++)//将[i,j]这个区间移到k后面
            {
                for(int o=1;o<=n;o++) tmp[now][o]=a[o];//保存状态
                int x,y;
                for(x=j+1,y=i;x<=k;x++,y++) a[y]=tmp[now][x];
                for(x=i;x<=j;x++,y++) a[y]=tmp[now][x];
                if(dfs(now+1,mx)) return true;
                for(int o=1;o<=n;o++) a[o]=tmp[now][o]; 
            }

        }
    }
    return false;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int depth=0;
    while(depth<5&&!dfs(0,depth)) depth++;
    if(depth>=5)
    {
        cout<<"5 or more"<<endl;
        return;
    }
    cout<<depth<<endl;
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