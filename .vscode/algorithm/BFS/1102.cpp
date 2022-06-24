#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define INF 0x3f3f3f3f
int n,k;
int dis[MAXN];

void solve()
{
    cin>>n>>k;
    memset(dis,0x3f,sizeof dis);
    dis[n]=0;
    queue <int> q;
    q.push(n);
    while(q.size())
    {
        int now=q.front();q.pop();
        if(now==k)
        {
            cout<<dis[now]<<endl;
            return;
        }
        else if(now>k)
        {
            dis[k]=min(dis[k],dis[now]+now-k);
            continue;
        }
        if(dis[now-1]>dis[now]+1&&now-1>=0)
        {
            dis[now-1]=dis[now]+1;
            q.push(now-1);
        }
        if(dis[now+1]>dis[now]+1&&now+1<=k)
        {
            dis[now+1]=dis[now]+1;
            q.push(now+1);
        }
        if(dis[now*2]>dis[now]+1&&now*2<=2*k)
        {
            dis[now<<1]=dis[now]+1;
            q.push(now<<1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}