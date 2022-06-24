#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 10
int ans[MAXN];
int n;

void dfs(int now,int pre,int rem)
{
    if(rem==0&&now!=2)
    {
        for(int i=1;i<now-1;i++)
        cout<<ans[i]<<"+";
        cout<<ans[now-1]<<endl;
        return;
    }

    for(int i=pre;i<=rem;i++)
    {
        ans[now]=i;
        dfs(now+1,i,rem-i);
        ans[now]=0;
    }
}

void solve()
{
    cin>>n;
    dfs(1,1,n);
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}