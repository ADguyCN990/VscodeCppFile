#include<bits/stdc++.h>
using namespace std;
#define MAXN 10005
#define ll long long
int n,m,V,cnt;
map <int,int> mp;//根据祖先节点找cnt
int f[MAXN];
int val[MAXN],vv[MAXN];
int w[MAXN],v[MAXN];
ll dp[MAXN];
int findx(int x)
{
    if(x==f[x]) return x;
    else return f[x]=findx(f[x]);
}

void merge(int x,int y)
{
    int fx=findx(x);
    int fy=findx(y);
    if(fy!=fx) f[fy]=fx;
}

void solve()
{
    cin>>n>>m>>V;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=n;i++)
    {
        cin>>vv[i]>>val[i];
    }
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        merge(u,v);
    }
    for(int i=1;i<=n;i++)
    {
        int fa=findx(i);
        if(!mp.count(fa))
        {
            cnt++;
            mp[fa]=cnt;
            v[cnt]=vv[i],w[cnt]=val[i];
        }
        else
        {
            v[mp[fa]]+=vv[i],w[mp[fa]]+=val[i];
        }
    }
    // cout<<cnt<<endl;
    // for(int i=1;i<=cnt;i++)
    //     cout<<"v: "<<v[i]<<" "<<"w: "<<w[i]<<endl;
    //选i个物品花不超过j的钱最多能买多少价值的物品
    for(int i=1;i<=cnt;i++)
    {
        for(int j=V;j>=v[i];j--)
        {
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    cout<<dp[V];
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}