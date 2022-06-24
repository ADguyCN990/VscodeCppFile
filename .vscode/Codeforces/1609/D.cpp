#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int n,m;
int f[MAXN];
int siz[MAXN];

int findx(int x)
{
    if(x==f[x]) return x;
    else return f[x]=findx(f[x]);
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) f[i]=i,siz[i]=1;
    int cnt=0;//剩余操作数
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        int x=findx(u),y=findx(v);
        if(x==y) cnt++;
        else
        {
            f[y]=x;
            siz[x]+=siz[y];
        }
        vector <int> ve;
        for(int i=1;i<=n;i++)
            if(f[i]==i)
                ve.emplace_back(siz[i]);
        sort(ve.begin(),ve.end(),greater<int>());
        int ans=0;
        for(int i=0;i<=cnt&&i<ve.size();i++)
            ans+=ve[i];
        cout<<ans-1<<endl;//除了自己
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}