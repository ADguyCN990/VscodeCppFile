#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
typedef pair<int,int> pii;
map <int,int> mp;
int n;
int a[MAXN],f[MAXN],op[MAXN];
pii p[MAXN];

int findx(int x)
{
    if(x==f[x]) return x;
    else return f[x]=findx(f[x]);
}

void merge(int x,int y)
{
    int fx=findx(x);
    int fy=findx(y);
    if(fy!=fx) f[fy]=fx;
}

void solve()
{
    mp.clear();
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int u,v;
        cin>>u>>v>>op[i];
        if(!mp.count(u)) cnt++,mp[u]=cnt;
        if(!mp.count(v)) cnt++,mp[v]=cnt;
        p[i].first=mp[u],p[i].second=mp[v];
    }
    //cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++) f[i]=i;
    for(int i=1;i<=n;i++)
    {
        if(op[i]==0) continue;
        merge(p[i].first,p[i].second);
    }
    for(int i=1;i<=n;i++)
    {
        if(op[i]==1) continue;
        int fx=findx(p[i].first);
        int fy=findx(p[i].second);
        if(fx==fy)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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