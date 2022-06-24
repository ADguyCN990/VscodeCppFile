#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define MAXM 400005
int type;//有向图 or 无向图
int n,m;//点,边的数量
int ans[MAXM],cnt;//记录欧拉回路用
int vis[MAXM];//标记某条边有没有走过
int indgr[MAXN],oudgr[MAXN];//点的入度和出度来表示度数

int head[MAXN];int tot;
struct EDGE
{
    int to,next;
}edge[MAXM];
void add_edge(int from,int to)
{
    edge[++tot].to=to;edge[tot].next=head[from];head[from]=tot;
}

int get(int x)
{
    if(x&1) return x+1;
    else return x-1;
}

void dfs(int now)
{
    for(int &i=head[now];i;)//改变引用后就能直接删边了
    {
        if(vis[i])//这条边用过了
        {
            i=edge[i].next;//删除这条边
            continue;
        }
        vis[i]=1;
        if(type==1)//如果是无向边，反向边也要标记删除
            vis[get(i)]=1;
        int id;//表示边的编号
        if(type==1)//无向图
        {
            id=(i+1)/2;
            if(i%2==0) //本题特有的脑瘫条件，不用管
                id=-id;
        }
        else //有向图
            id=i;
        int j=edge[i].to;
        i=edge[i].next;
        dfs(j);
        ans[++cnt]=id;
    }
}

void solve()
{
    cin>>type;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        add_edge(u,v);
        if(type==1)//如果是无向图
            add_edge(v,u);
        indgr[v]++,oudgr[u]++;
    }
    //判断度数合法性
    if(type==2)
    {
        for(int i=1;i<=n;i++)
        {
            if(indgr[i]!=oudgr[i])
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if((indgr[i]+oudgr[i])&1)
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    //判断连通性，需要找一个非孤立点作为起点去遍历图
    for(int i=1;i<=n;i++)
    {
        if(head[i]!=0)
        {
           dfs(i);
           break;
        }
    }
    if(cnt<m)
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    for(int i=cnt;i>0;i--)
        cout<<ans[i]<<" ";
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}