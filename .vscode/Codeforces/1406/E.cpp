#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int n;
map <int,pair<pii,pii>> mp;//pii的second为id，first为LCA。
//map[v] 的意义为 求出某两个点到v这个点的最短距离之和
//换句话说 v就是两个点的根，要求的就是LCA
int get(int now)
{
    int ans=1;
    while(ans<now)
    {
        ans*=2;
    }
    return ans-now;
}

void solve()
{
    n=read();
    priority_queue <int> q;//大根堆,大的放前面
    rep(i,1,n)
    {
        int tmp=read();
        q.push(tmp);
        mp[tmp].first={0,i};
    }
    while(q.size())
    {
        int now=q.top();q.pop();
        if(q.size()&&now==q.top()) continue;
        //
        if(now!=1)
        {
            int to=get(now);
            q.push(to);
            pii u=mp[now].first;
            u.first++;
            if(mp[to].first<u)
            {
                mp[to].second=mp[to].first;
                mp[to].first=u;
            }
            else if(mp[to].second<u)
            {
                mp[to].second=u;
            }
        }
    }
    int x,y,val;
    int root;
    val=-1;
    for(auto id:mp)
    {
        pair<pii,pii> now=id.second;
        if(now.first.second==0||now.second.second==0) continue;
        if(val<now.first.first+now.second.first)
        {
            val=now.first.first+now.second.first;
            x=now.first.second;
            y=now.second.second;
            root=id.first;
        }

    }
    cout<<x<<" "<<y<<" "<<val<<endl;
    //cout<<"!!!"<<root<<endl;
}

int main()
{
    solve();
    return 0;
}