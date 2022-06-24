#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 505
#define MAXM 2105
int mp[MAXN][MAXN];
int d[MAXN];//存储度数
int n,m;
int ans[MAXM],cnt;

void dfs(int now)
{
    for(int i=1;i<=500;i++)
    {
        if(mp[now][i])
        {
            mp[now][i]--,mp[i][now]--;//删边
            dfs(i);//爆搜
        }
    }
    ans[++cnt]=now;//记录答案
}

void solve()
{
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        mp[u][v]++,mp[v][u]++;
        d[u]++,d[v]++;
    }    
    int start=0;
    while(!d[start]) start++;
    for(int i=1;i<=500;i++)
    {
        if(d[i]&1)
        {
            start=i;
            break;
        }
    }
    dfs(start);
    for(int i=cnt;i;i--)
        cout<<ans[i]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}