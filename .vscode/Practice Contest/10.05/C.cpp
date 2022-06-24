#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
int k=1;
int n;
int x,y;
int head[MAXN],siz[MAXN],son[MAXN],father[MAXN],ans1[MAXN],ans2[MAXN];
struct edge
{
    int from,to,next;
}edge[MAXN*2];
void add_edge(int x,int y)
{
    edge[k].from=x;edge[k].to=y;edge[k].next=head[x];
    head[x]=k++;
}
void dfs(int s)
{
    siz[s]=1;
    son[s]=0;
    for(int i=head[s];i;i=edge[i].next)
    {
        if(edge[i].to!=father[s])
        {
            father[edge[i].to]=s;
            dfs(edge[i].to);
            siz[s]+=siz[edge[i].to];
            if(siz[edge[i].to]>siz[son[s]])
            {
                son[s]=edge[i].to;
            }
        }
    }
}

void dfss(int s)
{
    ans1[s]=x;ans2[s]=y;
    if(son[s]==0) return;
    y++;
    for(int i=head[s];i;i=edge[i].next)
    {
        if(edge[i].to!=son[s]&&edge[i].to!=father[s])
        {
            dfss(edge[i].to);
            x++;
        }
    }
    y--;
    x++;
    dfss(son[s]);
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        add_edge(x,y);add_edge(y,x);
    }
    dfs(1);
    x=1;y=1;
    dfss(1);
    for(int i=1;i<=n;i++)
    {
        cout<<ans1[i]<<" "<<ans2[i]<<endl;
    }
    return 0;
}