#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define MAXN 1005
#define MAXM 1005
int n,m,T;
int dfn[MAXN],num,low[MAXN],dcc,iscut[MAXN],root;
stack <int> st;
vector <int> dccc[MAXN];
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
    for(int i=1;i<=dcc;i++) dccc[i].clear();
    memset(head,0,sizeof(head));
    tot=num=dcc=n=0;
    memset(dfn,0,sizeof(dfn));
    memset(iscut,0,sizeof(iscut));
    
}

void tarjan(int x)
{
    dfn[x]=low[x]=++num;
    st.push(x);
    if(x==root&&head[x]==0)//特判孤立点
    {
        dcc++;
        dccc[dcc].emplace_back(x);
        return;
    }
    int cnt=0;//统计裂开的块的的个数
    for(int i=head[x];i;i=edge[i].next)
    {
        int y=edge[i].to;
        if(!dfn[y])
        {
            tarjan(y);
            low[x]=min(low[x],low[y]);
            if(dfn[x]<=low[y])//y无法到达x的祖先
            {
                cnt++;
                if(x!=root||cnt>1) 
                    iscut[x]=1;//x是割点
                dcc++;
                int now=-1;
                while(now!=y)
                {
                    now=st.top();st.pop();
                    dccc[dcc].emplace_back(now);
                }
                dccc[dcc].emplace_back(x);//把x也要push进去
            }
        }
        else    
            low[x]=min(low[x],dfn[y]);
    }
}

void solve()
{
    init();
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        n=max({a,b,n});
        add_edge(a,b),add_edge(b,a);
    }
    for(root =1;root <=n;root++)
    {
        if(!dfn[root])
            tarjan(root);
    }
    int mx=0;
    ull ans=1;
    for(int i=1;i<=dcc;i++)
    {
        int cnt=0;//统计一个点双连通分量内的割点个数
        for(int j=0;j<dccc[i].size();j++)
        {
            if(iscut[dccc[i][j]]==1)//如果是割点
                cnt++;
        }
        if(cnt==0)
        {
            if(dccc[i].size()>1)
                mx+=2,ans*=dccc[i].size()*(dccc[i].size()-1)/2;
            else
                mx++;
        }
        else if(cnt==1)
            mx++,ans*=(dccc[i].size()-1);
    }
    cout<<"Case "<<T<<": "<<mx<<" "<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    T=0;
    while(cin>>m)
    {
        if(!m) break;
        T++;
        solve();
    }

    return 0;
}