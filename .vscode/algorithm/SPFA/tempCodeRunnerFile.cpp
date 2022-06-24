#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 600
#define MAXM 100005
#define INF 0x3f3f3f3f
#define exp 1e-4
int vis[MAXN+5],cnt[MAXN+5];
double dis[MAXN+5];
int head[MAXN+5];int tot;
int n,m;
struct EDGE
{
    int to,next;
    double val;
}edge[MAXM];
void add_edge(int from,int to,double val)
{
    edge[++tot].to=to;edge[tot].val=val;edge[tot].next=head[from];head[from]=tot;
}

bool check(double mid)
{
    queue <int> q;
    for(int i=0;i<=MAXN;i++)
    {
        vis[i]=1;
        dis[i]=0;
        cnt[i]=0;
        q.push(i);
    }
    int count=0;
    while(!q.empty())
    {
        int now=q.front();q.pop();vis[now]=0;
        for(int i=head[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            double val=mid-edge[i].val+0.0;
            if(dis[to]>dis[now]+val)
            {
                dis[to]=dis[now]+val;
                cnt[to]=cnt[now]+1;
                if(++count>2*MAXN)
                    return true;
                if(cnt[to]>=MAXN)
                    return true;
                if(!vis[to])
                {
                    vis[to]=1;
                    q.push(to);
                }
            }
        }
    }
    return false;
}

void solve()
{
    for(int i=1;i<=m;i++)
    {
        string s;
        cin>>s;
        double len=s.length()+0.0;
        if(s.length()<2) continue;
        int from=(s[0]-'a')*26+s[1]-'a';
        int to=(s[s.length()-2]-'a')*26+s[s.length()-1]-'a';
        add_edge(from,to,len);
    }
    if(!check(0.0))
    {
        cout<<"No solution"<<endl;
        return;
    }
    double l=0;double r=1000;
    double ans;
    while(r-l>=exp)
    {
        double mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            l=mid;
        }
        else
            r=mid;
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin>>m)
    {
        if(!m) break;
        solve();
    }
    
    return 0;
}