#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
ll n;
int deep[MAXN];//每个节点的深度
int width[MAXN];//每个深度的节点个数
int fa[MAXN];//每个节点的父亲节点
int lca(int x,int y)//两个节点的最近公共祖先
{
    if(x==y) return x;
    else if(deep[x]==deep[y]) return lca(fa[x],fa[y]);
    else if(deep[x]>deep[y]) return lca(fa[x],y);
    else if(deep[x]<deep[y]) return lca(x,fa[y]);
}
void solve()
{
    cin>>n;
    deep[1]=1;
    for(int i=1;i<n;i++)
    {
        int u,v;//u是父亲，v是孩子
        cin>>u>>v;
        deep[v]=max(deep[v],deep[u]+1);
        fa[v]=u;
    }
    int max_depth=0;
    for(int i=1;i<=n;i++)
    {
        max_depth=max(max_depth,deep[i]);
        width[deep[i]]++;
    }
    int max_width=0;
    for(int i=1;i<=n;i++)
    {
        max_width=max(max_width,width[i]);
    }

    int u,v;
    cin>>u>>v;
    cout<<max_depth<<endl<<max_width<<endl;
    int k=lca(u,v);
    cout<<(deep[u]-deep[k])*2+(deep[v]-deep[k])<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}