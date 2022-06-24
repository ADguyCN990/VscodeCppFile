#include<bits/stdc++.h>
using namespace std;
#define MAXN 400005
#define ll long long
//反向建图，然后拓扑排序
ll n,m;
vector <int> mp[MAXN];//邻接矩阵建图
int tim[MAXN];
int indgr[MAXN];
ll ans;
struct node
{
    ll id;
    ll time;
    bool operator <(const node &a) const
    {
        return time>a.time;
    }
};
void build()
{
    for(int i=1;i<=n;i++)
    {
        cin>>tim[i];
        cin>>m;
        while(m--)
        {
            int son;
            cin>>son;//前置会议
            mp[i].emplace_back(son);
            indgr[son]++;
        }
    }
}
void topu()
{
    priority_queue <node> q;
    for(int i=1;i<=n;i++) if(indgr[i]==0) q.push(node{i,tim[i]});
    int extra_time=n-1;//能同一轮进行的会议最少需要隔开一分钟
    while(!q.empty())
    {
        node temp=q.top();q.pop();
        ll now=temp.id;ll time=temp.time+extra_time;
        ans=max(ans,time);
        extra_time--;
        for(auto it:mp[now])
        {
            indgr[it]--;
            if(indgr[it]==0) q.push(node{it,tim[it]});
        }
    }
}
void solve()
{
    cin>>n;
    build();
    topu();
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}