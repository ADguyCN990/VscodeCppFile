#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
#define MAXM 700005
#define MAXN 100005
ll n,m;
ll head[MAXM];int cnt=0;
ll cnt_[MAXN];//以i为终点的路径数量
ll sum[MAXN];//以i为终点的路径长度
struct node
{
    int to,next;
}edge[MAXM];

void add_edge(int from,int to)
{
    edge[++cnt].to=to;edge[cnt].next=head[from];head[from]=cnt;
}

int indgr[MAXN];int outdgr[MAXN];

ll quickpow(ll a,ll n)//快速幂，除法取模用
{
    ll ans=1;
    while(n)
    {
        if(n%2==1)
        {
            ans=(a*ans)%mod;
            n--;
        }
        else if(n%2==0)
        {
            a=(a*a)%mod;
            n/=2;
        }
    }
    return ans;
}

ll dive(ll a,ll b)//除法取模
{
    return (a*quickpow(b,mod-2))%mod;
}

void build()
{
    for(int i=1;i<=n;i++) cnt_[i]=1;//路径个数至少为1
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        indgr[v]++;
        add_edge(u,v);
    }
}

void topp()
{
    queue <int> q;
    for(int i=1;i<=n;i++)
    {
        if(indgr[i]==0) q.push(i);
    }
    while(!q.empty())
    {
        int now=q.front();q.pop();
        for(int i=head[now];i;i=edge[i].next)
        {
            int j=edge[i].to;
            cnt_[j]=(cnt_[j]+cnt_[now])%mod;//路径个数等于入度节点的路径个数之和
            sum[j]=(sum[j]+sum[now]+cnt_[now])%mod;//路径长度等于入度节点的(路径长度+1)之和，以某个入度节点为终点的路径条数为cnt[now]
            indgr[j]--;
            if(indgr[j]==0)
            {
                q.push(j);
            }
        }
    }
}

void output()
{
    ll SUM=0;ll COUNT=0;
    for(int i=1;i<=n;i++)
    {
        SUM=(SUM+sum[i])%mod;
        COUNT=(COUNT+cnt_[i])%mod;
    }
    //cout<<SUM<<" "<<COUNT<<endl;
    cout<<dive(SUM,COUNT)<<endl;
}

void solve()
{
   
    cin>>n>>m;
    build();
    topp();
    output();
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}