#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define MAXM 300005
int vis[MAXN],dis[MAXN],cnt[MAXN],n,m;

int head[MAXN];int tot;
struct EDGE
{
    int to,next,val;
}edge[MAXM];
void add_edge(int from,int to,int val)
{
    edge[++tot].to=to;edge[tot].val=val;edge[tot].next=head[from];head[from]=tot;
}

bool spfa(int s)
{
    stack <int> st;
    vis[s]=1;
    st.push(s);
    while(!st.empty())
    {
        int now=st.top();st.pop();vis[now]=0;
        for(int i=head[now];i!=-1;i=edge[i].next)
        {
            int to=edge[i].to;
            int val=edge[i].val;
            if(dis[to]<dis[now]+val)
            {
                dis[to]=dis[now]+val;
                cnt[to]=cnt[now]+1;
                if(cnt[to]>=n+1)
                    return false;//存在负环，无解
                if(!vis[to])
                {
                    st.push(to);
                    vis[to]=1;
                }
            }
        }
    }
    return true;
}

void solve()
{
    cin>>n>>m;
    for(int i=0;i<=n;i++)
        head[i]=-1;
    for(int i=1;i<=m;i++)
    {
        int f,a,b;
        cin>>f>>a>>b;
        if(f==1) 
            add_edge(a,b,0),add_edge(b,a,0);
        else if(f==2)
            add_edge(a,b,1);
        else if(f==3)
            add_edge(b,a,0);
        else if(f==4)
            add_edge(b,a,1);
        else if(f==5)
            add_edge(a,b,0);
    }
    for(int i=1;i<=n;i++)
        add_edge(0,i,1);
    if(!spfa(0))
    {
        cout<<-1<<endl;
        return;
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=dis[i];
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}