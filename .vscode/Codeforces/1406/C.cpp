#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

int head[MAXN];int tot;
struct EDGE
{
    int to,next;
}edge[MAXM];
void add_edge(int from,int to)
{
    edge[++tot].to=to;edge[tot].next=head[from];head[from]=tot;
}

int fa[MAXN];
ll siz[MAXN];
ll dp[MAXN];
ll n;

void init()
{
    rep(i,1,n)
    {
        siz[i]=1;
        fa[i]=0;
        head[i]=0;
        dp[i]=0;//最大子树节点的个数
    }
    tot=0;
}

int dfs(int now,int pre)
{
    fa[now]=pre; 
    for(int i=head[now];i;i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==pre) continue;
        siz[now]+=dfs(to,now);
    }
    return siz[now];
}

void solve()
{
    n=read();
    init();
    int u,v;
    rep(i,1,n-1)
    {
        cin>>u>>v;
        add_edge(u,v),add_edge(v,u);
    }
    dfs(1,0);
    ll mn=INF;
    rep(now,1,n)
    {
        dp[now]=n-siz[now];
        for(int i=head[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            if(to==fa[now]) continue;
            dp[now]=max(dp[now],siz[to]);
            
        }
        mn=min(mn,dp[now]);
    }
    //rep(i,1,n) cout<<"!!! "<<i<<" "<<dp[i]<<endl;
    vector <int> ve;
    rep(i,1,n)
    {
        if(dp[i]==mn) ve.emplace_back(i); 
    }
    if(ve.size()==1)
    {
        cout<<u<<" "<<v<<endl;
        cout<<u<<" "<<v<<endl;
    }
    else if(ve.size()==2)
    {
        //cout<<"!!! "<<ve[0]<<" "<<ve[1]<<endl;
        int to=edge[head[ve[0]]].to;
        if(to==ve[1])
        to=edge[edge[head[ve[0]]].next].to;
        cout<<ve[0]<<" "<<to<<endl;
        cout<<ve[1]<<" "<<to<<endl;
    }
}

int main()
{
    int T;
    T=read();
    while(T--)
    {
        solve();
    }

    return 0;
}