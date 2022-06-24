#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
int n,m;
int f[MAXN];
int cnt[MAXN];//关系的数量
int siz[MAXN];//元素的数量
int vis[MAXN];
void init()
{
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++) siz[i]=1,f[i]=i,vis[i]=0;
}

int findx(int x)
{
    if(x==f[x]) return x;
    else return f[x]=findx(f[x]);
}

void merge(int x,int y)
{
    int fx=findx(x),fy=findx(y);
    cnt[fx]++;
    if(fx!=fy)
    {
        siz[fx]+=siz[fy];
        cnt[fx]+=cnt[fy];
        f[fy]=fx;
    }
}

void solve()
{
    int ans=0;
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        merge(u,v);
    }
    for(int i=1;i<=n;i++)
    {
        int fx=findx(f[i]);
        if(!vis[fx])
        {
            int num=siz[fx];
            int edge=cnt[fx];
            if(edge-num>0)
                ans+=edge-num;
            vis[fx]=1;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}