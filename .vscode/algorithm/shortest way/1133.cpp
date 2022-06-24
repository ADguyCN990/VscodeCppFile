#include<bits/stdc++.h>
using namespace std;
#define MAXN 15
#define MAXM 1005
#define ll long long
#define INF 0x3f3f3f3f
typedef pair<int,int> pii;
int n,m,k;//nm的矩阵，k条特殊边
int p=1<<10;//钥匙的种类
map <pii,int> mp;//存放特殊边
int head[MAXM];int cnt;int key[MAXM];
int dis[MAXM][1<<10];
int vis[MAXM][1<<10];
struct edge
{
    int to,next,val;
}edge[MAXM];
void add_edge(int from,int to,int val)//val表示钥匙,若val为0表示中间没有钥匙
{
    edge[++cnt].to=to;edge[cnt].val=val;edge[cnt].next=head[from];head[from]=cnt;
}
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int get(pii a)
{
    return (a.first-1)*m+a.second;
}
bool ok(int x,int y)
{
    if(x<1||x>n||y<1||y>m) return false;
    return true;
}
void rebuild()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int u=0;u<4;u++)
            {
                int x=i+dx[u];int y=j+dy[u];
                int a=get(pii{i,j});
                int b=get(pii{x,y});
                if(mp[pii{a,b}]==0&&ok(x,y))
                {
                    add_edge(a,b,0);
                }
            }
        }
    }
}  

int bfs()
{
    memset(dis,INF,sizeof(dis));
    deque <pii> q;
    dis[1][0]=0;//起点
    q.push_back(pii{1,0});//first表示坐标位置，second表示拥有的钥匙的状态
    while(!q.empty())
    {
        pii t=q.front();q.pop_front();
        int now=t.first;
        int state=t.second;
        if(vis[now][state]) continue;
        vis[now][state]=1;
        if(now==n*m) return dis[now][state];
        if(key[now]!=0)//如果现在所处的位置有钥匙
        {
            int new_state=state|key[now];
            dis[now][new_state]=dis[now][state];//这句有改动，wa了注意一下
            q.push_front(pii{now,new_state});//边权为0的点推入队首
        }
        for(int i=head[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            int val=edge[i].val;
            if(val!=0&&!(state>>(val-1)&1)) continue;//有门且没有钥匙
            if(dis[to][state]>dis[now][state]+1)
            {
                dis[to][state]=dis[now][state]+1;
                q.push_back(pii{to,state});
            }
        }
    }
    return -1;
}

void solve()
{
    cin>>n>>m>>p>>k;
    for(int i=1;i<=k;i++)
    {
        pii a,b;
        int c;//c为0，表示为墙，不连边
        cin>>a.first>>a.second>>b.first>>b.second>>c;
        mp[pii{get(a),get(b)}]=1;
        mp[pii{get(b),get(a)}]=1;
        if(c!=0)
        {
            add_edge(get(a),get(b),c);add_edge(get(b),get(a),c);
        }
    }
    rebuild();
    int s;
    cin>>s;
    for(int i=1;i<=s;i++)
    {
        int x,y,c;
        cin>>x>>y>>c;
        key[get(pii{x,y})] |= (1 << c - 1);
    }
    cout<<bfs()<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}