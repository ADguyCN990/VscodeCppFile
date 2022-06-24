#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 10005
#define MAXM 20005
ll ans[MAXN];
ll n,m;
int indgr[MAXN];
int head[MAXM];int cnt;
struct node
{
    int to,next;
}edge[MAXM];
void add_edge(int from,int to)
{
    edge[++cnt].to=to;edge[cnt].next=head[from];head[from]=cnt;
}

void topu()
{
    queue <int> q;
    for(int i=1;i<=n;i++)
        if(indgr[i]==0)
            q.push(i);
    while(!q.empty())
    {
        int now=q.front();q.pop();
        //nxt的奖金要比now高
        for(int i=head[now];i;i=edge[i].next)
        {
            int nxt=edge[i].to;
            ans[nxt]=max(ans[nxt],ans[now]+1);
            indgr[nxt]--;
            if(indgr[nxt]==0) q.push(nxt);
        }
    }

}

void output()
{
    for(int i=1;i<=n;i++)
    {
        if(indgr[i]>0)
        {
            cout<<"Poor Xed"<<endl;
            return;
        }
    }
    ll sum=0;
    for(int i=1;i<=n;i++) sum+=ans[i];
    cout<<sum<<endl;
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) ans[i]=100;
    for(int i=1;i<=m;i++)
    {
        int from,to;
        cin>>from>>to;
        add_edge(to,from);
        indgr[from]++;
    }
    topu();
    output();
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}