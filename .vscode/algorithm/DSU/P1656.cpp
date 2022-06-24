#include<bits/stdc++.h>
using namespace std;
#define MAXN 155
#define MAXM 5005
struct node
{
    int u,v;
}e[MAXM];
bool cmp (node a,node b) 
{
    if(a.u==b.u) return a.v<b.v;
    return a.u<b.u;
}
int n,m;
int f[MAXN];
vector <node> ans;

int findx(int x)
{
    if(x==f[x]) return x;
    return f[x]=findx(f[x]);
}

void merge(int x,int y)
{
    int fx=findx(x);
    int fy=findx(y);
    if(fx!=fy) f[fy]=fx;
}

void work(int t)//删除的边编号为t
{
    for(int i=1;i<=n;i++) 
        f[i]=i;
    for(int i=1;i<=m;i++)
    {
        if(i==t) continue;
        merge(e[i].u,e[i].v);
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(f[i]==i)
            cnt++;
    }
    if(cnt>1)
        ans.emplace_back(e[t]);
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        if(u==v) continue;
        e[i].u=min(u,v);
        e[i].v=max(u,v);
    }
    sort(e+1,e+1+m,cmp);
    for(int i=1;i<=m;i++)
    {
        work(i);//删除第i条边，看剩下的是不是一个连通图
    }
    for(auto x:ans)
        cout<<x.u<<" "<<x.v<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    // int T;
    // cin>>T;
    // while(T--)
    // {
        solve();
    //}

    return 0;
}