#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 10
ll a[MAXN];
int vis[MAXN];
char op[MAXN];
int cnt=0;
ll b[MAXN];
ll ans=9999999999999999;

void dfs(int now)
{
    if(now>=4)
    {
        for(int i=1;i<=4;i++)
        {
            if(!vis[i])
            {
                ans=min(ans,a[i]);
                return;
            }
        }
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            ll tmp=a[i];
            if(i==j||vis[i]||vis[j]) continue;
            if(op[now]=='+')
                a[i]=a[i]+a[j];
            else if(op[now]=='*')
                a[i]=a[i]*a[j];
            vis[j]=1;
            dfs(now+1);
            vis[j]=0;
            a[i]=tmp;
        }
    }
}


void solve()
{
    cin>>a[1]>>a[2]>>a[3]>>a[4];
    cin>>op[1]>>op[2]>>op[3];
    dfs(1);
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}