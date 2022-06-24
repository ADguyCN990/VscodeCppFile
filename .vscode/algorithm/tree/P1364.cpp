#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
int visit[MAXN];
struct node
{
    int l;
    int r;
    int fa;
    int val;
}a[MAXN];

int dfs(int rt,int deep)
{  
    if(rt==0||visit[rt]==1) return 0;//保证每个点只遍历一次
    visit[rt]=1;
    return dfs(a[rt].l,deep+1)+dfs(a[rt].r,deep+1)+dfs(a[rt].fa,deep+1)+deep*a[rt].val;
}

void solve()
{
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].val>>a[i].l>>a[i].r;
        if(a[i].l!=0)  a[a[i].l].fa=i;
        if(a[i].r!=0) a[a[i].r].fa=i;
    }
    int ans=0x3f3f3f3f;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) visit[j]=0;
        ans=min(ans,dfs(i,0));
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}