#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define pb emplace_back
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

int n,m,s,t;
int head[MAXN];int tot;
struct EDGE
{
    int to,next,val;
}edge[MAXM];
void add_edge(int from,int to,int val)
{
    edge[++tot].to=to;edge[tot].val=val;edge[tot].next=head[from];head[from]=tot;
}
int get(int x)//求反向边的函数
{
    if(x&1) return x+1;
    return x-1;
}
int dis[MAXN];//距离
int pre[MAXN];//前驱
int vis[MAXN];

bool bfs()//求增广路径
{
    queue <int> q;
    q.push(s);
    rep(i,1,n) vis[i]=0;
    vis[s]=1;dis[s]=INF;
    while(q.size())
    {
        int now=q.front();q.pop();
        for(int i=head[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            int val=edge[i].val;
            if(!vis[to]&&val)
            {
                vis[to]=1;
                dis[to]=min(dis[now],val);
                pre[to]=i;
                if(to==t) return true;
                q.push(to);
            }
        }
    }
    return false;
}

int EK()
{
    int ans=0;
    while(bfs())
    {
        ans+=dis[t];
        for(int i=t;i!=s;i=edge[get(pre[i])].to)
        {
            edge[pre[i]].val-=dis[t];
            edge[get(pre[i])].val+=dis[t];
        }
    }
    return ans;
}

void solve()
{
    n=read(),m=read(),s=read(),t=read();
    while(m--)
    {
        int a,b,c;
        a=read(),b=read(),c=read();
        add_edge(a,b,c);
        add_edge(b,a,0);
        
    }
    int ans=EK();
    cout<<ans<<endl;
}

int main()
{
    solve();
    return 0;
}