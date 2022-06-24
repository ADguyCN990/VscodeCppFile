#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll n,x,m;
ll a[MAXN];
void solve()
{
    cin>>n>>m>>x;
    //塔和塔之间的差不超过x
    for(int i=1;i<=n;i++) cin>>a[i];
    cout<<"YES"<<endl;
    set <pair<int,int>> s;
    for(int i=1;i<=m;i++)
    {
        s.insert(make_pair(0,i));
    }
    for(int i=1;i<=n;i++)
    {
        pair<int,int> p=*s.begin();
        s.erase(p);
        s.insert(make_pair(p.first+a[i],p.second));
        cout<<p.second<<" ";
    }
    cout<<endl;
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