#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 15
#define INF 0x3f3f3f3f
int n;
int a[MAXN];
int mp[MAXN][MAXN];
int ans=MAXN;
int vis[MAXN];
ll gcd(ll a,ll b)
{
    if(a<b) swap(a,b);
    ll tmp;
    while(b)
    {
       tmp=b;
       b=a%b;
       a=tmp; 
    }
    return a;
}

bool check(int mp[],int s,int start)
{
    for(int j=0;j<start;j++)
    {
        if(gcd(a[mp[j]],s)>1)
            return false;
    }
    return true;
}

void dfs(int now,int g_cur,int t_cur,int start)
{
    if(now>=ans) return;//剪枝
    if(t_cur==n)//完成了所有数的枚举
    {
        ans=min(ans,now);
    }
    bool flag=true;
    for(int i=start;i<n;i++)
    {
        if(!vis[i]&&check(mp[now],a[i],g_cur))
        {
            vis[i]=1;
            mp[now][g_cur]=i;
            dfs(now,g_cur+1,t_cur+1,i+1);
            vis[i]=0;
            flag=false;
        }
    }
    if(flag) dfs(now+1,0,t_cur,0);
}

void solve()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    dfs(1,0,0,0);
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}