#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
typedef pair<long double,pair<int,int>> pdp;
priority_queue <pdp> q;
double x[MAXN];double v[MAXN];
ll n;
void add_edge(int a,int b)
{
    if(v[a]<=v[b]) return;//不可能撞上
     double t=(x[a]-x[b]-0.0)/(v[a]-v[b]-0.0);
    q.push(make_pair(t,make_pair(a,b)));
}

void solve()
{
    set <int> s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>v[i];
    }
    for(int i=1;i<=n;i++) s.insert(i);
    for(int i=1;i<=n-1;i++)
    {
        add_edge(i,i+1);
    }
    while(!q.empty()&&s.size()>0)
    {
        int a=q.top().second.first;
        int b=q.top().second.second;
        q.pop();
        if(!s.count(a)||!s.count(b))//之前已经撞飞了
            continue;
        s.erase(a);s.erase(b);
        //if(!s.size()) break;
        auto it=s.lower_bound(a);
        if(it==s.end()||it==s.begin()) //到了两端，前驱或后继有一个就没了
            continue;
        it--;
        int pre=*(it);
        int nxt=*(s.lower_bound(b));
        add_edge(pre,nxt);//下次可能撞的
    }
    cout<<s.size()<<endl;
    for(auto x:s) cout<<x<<" ";
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}