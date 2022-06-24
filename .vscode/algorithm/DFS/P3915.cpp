#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int n,k,cnt;int siz[MAXN];

int head[MAXN];int tot;
struct EDGE
{
    int to,next;
}edge[MAXM];
void add_edge(int from,int to)
{
    edge[++tot].to=to;edge[tot].next=head[from];head[from]=tot;
}

void init()
{
    tot=0;cnt=0;
    memset(head,0,sizeof head);
    memset(siz,0,sizeof siz);
}

int dfs(int now,int pre)
{
    siz[now]=1;
    for(int i=head[now];i;i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==pre) continue;
        siz[now]+=dfs(to,now);
    }
    if(siz[now]==k) 
    {
        cnt++;
        siz[now]=0;
    }
    return siz[now];
}

void solve()
{
    init();
    cin>>n>>k;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        add_edge(u,v),add_edge(v,u);
    }
    if(n%k)
    {
        cout<<"NO"<<endl;
        return;
    }
    dfs(1,-1);
    if(cnt==n/k)
    {
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}