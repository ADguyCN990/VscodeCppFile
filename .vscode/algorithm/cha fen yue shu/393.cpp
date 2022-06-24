#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 30
#define MAXM 105
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int vis[MAXN],cnt[MAXN],dis[MAXN];
int num[MAXN],r[MAXN],n,m;//num表示这个在i这个时间点上八小时班的人数，r表示i~i+1这个时间段需要的人数
int head[MAXN];int tot;
struct EDGE
{
    int to,next,val;
}edge[MAXM];
void add_edge(int from,int to,int val)
{
    edge[++tot].to=to;edge[tot].val=val;edge[tot].next=head[from];head[from]=tot;
}

bool check(int mid)
{
    memset(head,-1,sizeof(head));tot=0;//每次都要重新建图
    for(int i=1;i<=24;i++)
    {
        add_edge(i-1,i,0),add_edge(i,i-1,-num[i]);
        if(i>=8)
            add_edge(i-8,i,r[i]);
        else
            add_edge(i+16,i,r[i]-mid);
    }
    //我们已经规定sum[24]为定值x，加一个sum[24]=x的限制条件。
    add_edge(0,24,mid),add_edge(24,0,-mid);
    for(int i=0;i<=24;i++)
    {
        vis[i]=0,cnt[i]=0,dis[i]=-INF;
    }
    dis[0]=0,vis[0]=1;
    queue <int> q;q.push(0);
    while(!q.empty())
    {
        int now=q.front();q.pop();vis[now]=0;
        for(int i=head[now];i!=-1;i=edge[i].next)
        {
            int to=edge[i].to;
            int val=edge[i].val;
            if(dis[to]<dis[now]+val)
            {
                dis[to]=dis[now]+val;
                cnt[to]=cnt[now]+1;
                if(cnt[to]>=24+1)//一共有25个点，不是n个点
                    return false;
                if(!vis[to])
                    vis[to]=1,q.push(to);
            }
        }
    }
    return true;
}

void solve()
{
    memset(num,0,sizeof(num));
    for(int i=1;i<=24;i++)
        cin>>r[i];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        num[++tmp]++;
    }
    int l=0;int r=n+1;//一共有n个岗位，普通数组转化为前缀和下标加1
    int ans=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    if(ans==-1)
        cout<<"No Solution"<<endl;
    else
        cout<<ans<<endl;
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