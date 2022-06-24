#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 25
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
string dic[MAXN];
int mp[MAXN][MAXN];
int vis[MAXN];//计数
int n;
int ans;
char start;

void dfs(int dragon,int last)
{
    ans=max(ans,dragon);
    for(int i=1;i<=n;i++)
    {
        if(mp[last][i]&&vis[i]<2)
        {
            vis[i]++;
            dfs(dragon+dic[i].size()-mp[last][i],i);
            vis[i]--;
        }
    }
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>dic[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=min(dic[i].size(),dic[j].size());k++)
            {
                string a=dic[i],b=dic[j];
                if(a.substr(a.size()-k,k)==b.substr(0,k))
                {
                    mp[i][j]=k;
                    break;
                }
            }
        }
    }
    cin>>start;
    for(int i=1;i<=n;i++)
    {
        if(dic[i][0]==start)
        {
            vis[i]++;
            dfs(dic[i].size(),i);
        }
        memset(vis,0,sizeof vis);  
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}