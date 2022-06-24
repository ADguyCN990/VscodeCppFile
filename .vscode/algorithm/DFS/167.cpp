#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 25
int n,mx;
int a[MAXN];
int rem[MAXN];//某辆车剩余的空间
int ans=MAXN;
bool cmp(int a,int b) {return a>b;}

void dfs(int now,int k)//当前的猫，当前拥有的车的数量
{
    if(k>=ans) return;
    if(now==n+1)
    {
        ans=k;
        return;
    }
    for(int i=1;i<=k;i++)
    {   
        if(a[now]<=rem[i])
        {
            rem[i]-=a[now];
            dfs(now+1,k);
            rem[i]+=a[now];
        }
    }

    rem[k+1]-=a[now];
    dfs(now+1,k+1);
    rem[k+1]+=a[now];
}

void solve()
{
    cin>>n>>mx;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
        rem[i]=mx;
    dfs(1,1);
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}