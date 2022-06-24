#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
#define MAXM 300005
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

int f[MAXN];//并查集的父亲
int siz[MAXN];//连通块个数
int n,m;//点，边
int color[MAXN];//点权，本题为点的颜色
vector <int> g[MAXN];//邻接矩阵建图
int findx(int x)
{
    if(x==f[x]) return x;
    else return f[x]=findx(f[x]);
}
void merge(int x,int y)
{
    int fx=findx(x);
    int fy=findx(y);
    if(fy!=fx) siz[fx]+=siz[fy],f[fy]=fx;
}

map <int,int> vis,cnt;//vis为标记状态，cnt表示为某个颜色的连通块数量

void solve()
{
    n=read(),m=read();
    rep(i,1,n) color[i]=read();//读入点权
    rep(i,1,n)//并查集初始化
    {
        f[i]=i;
        siz[i]=1;
    }
    rep(i,1,m)
    {
        int u,v;
        u=read(),v=read();
        g[u].pb(v),g[v].pb(u);//邻接矩阵建图
        if(color[u]==color[v]) merge(u,v);//颜色相同就连边，维护连通块
    }
    int ans=1;
    rep(i,1,n)//遍历，假设改变该点的颜色
    {
        int now=i;
        cnt.clear(),vis.clear();//每次变换颜色的点都不同，所以每次都要初始化
        for(auto to:g[now])//遍历所有邻边
        {
            int rt=findx(to);//to所在连通块的根
            int c=color[rt];//to的颜色
            int num=siz[rt];//to所在连通块的个数
            if(!vis[rt])//以rt为根的这个连通块之前还未遍历过
            {
                vis[rt]=1;//打上标记，表示已经访问过该连通块，避免重复计算
                cnt[color[rt]]+=siz[rt];//累加上这个连通块的贡献
            }
        } 
        for(auto x:cnt)
        {
            if(color[now]==x.first)//两者颜色相同
                ans=max(ans,x.second);
            else
                ans=max(ans,x.second+1);
        }  
    }
    cout<<ans<<endl;
}

int main()
{
    solve();
    return 0;
}