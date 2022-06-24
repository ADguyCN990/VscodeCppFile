#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
int color[MAXN];//表示每个点的颜色，-1表示还未染色
int n,m;

int head[MAXN];int tot;
struct EDGE
{
    int to,next;
}edge[MAXM];
void add_edge(int from,int to)
{
    edge[++tot].to=to;edge[tot].next=head[from];head[from]=tot;
}
bool dfs(int now,int c)//x表示点编号，c表示颜色
{
    color[now]=c;
    for(int i=head[now];i;i=edge[i].next)
    {
        int to=edge[i].to;
        if(color[to]==-1)
        {
            if(!dfs(to,!c))//搜完后出现了矛盾
                return false;
        }
        else if(color[to]==c)//之前的结果和现在的结果产生矛盾 
            return false;
    }
    return true;
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) color[i]=-1;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        add_edge(u,v),add_edge(v,u);
    }
    for(int i=1;i<=n;i++)
    {
        if(color[i]==-1)
        {
            if(!dfs(i,0))
            {
                cout<<"No"<<endl;
                return;
            }
        }
    }
    cout<<"Yes"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}