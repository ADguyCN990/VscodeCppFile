#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 505
#define MAXM 200005
#define INF 0x3f3f3f3f
typedef pair <int,int> pii;
typedef pair<ll,ll> pll;
int vis[MAXN];int dis[MAXN];

int head[MAXM];int cnt;
struct Edge
{
    int to,next;
}edge[MAXM];
void add_edge(int from,int to)
{
    edge[++cnt].to=to;edge[cnt].next=head[from];head[from]=cnt;
}

ll n,m;



void dij(int s)
{
    for(int i=1;i<=n;i++) vis[i]=0;
    for(int i=1;i<=n;i++) dis[i]=INF;
    dis[1]=0;
    priority_queue<pii> q;//换乘次数，标号
    q.push({0,1});
    
    while(!q.empty())
    {
        int now=q.top().second;q.pop();
        if(vis[now]) continue;
        vis[now]=1;
        for(int i=head[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
       
            if(dis[to]>dis[now]+1)
            {
                dis[to]=dis[now]+1;
                q.push({-dis[to],to});
            }
        }
    }
}

void solve()
{
    cin>>m>>n;
    cin.ignore();
    for(int k=1;k<=m;k++)
    {
        string s="";
        getline(cin,s);      
        //cout<<s<<endl;
        vector <int> ve;
        int tmp=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ') 
            {
                ve.emplace_back(tmp);
                tmp=0;
            }
            else 
            {
                tmp=tmp*10+(s[i]-'0');
                if(i==s.length()-1)
                    ve.emplace_back(tmp);
            }
                
        }
        for(int i=0;i<ve.size()-1;i++)
        {
            for(int j=i+1;j<ve.size();j++)
            {
                add_edge(ve[i],ve[j]);
                //cout<<ve[i]<<" "<<ve[j]<<endl;
            }
        }
    }
    dij(1);
    if(dis[n]==INF) cout<<"NO"<<endl;
    else if(dis[n]==0) cout<<0<<endl;
    else cout<<dis[n]-1<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();

    return 0;
}