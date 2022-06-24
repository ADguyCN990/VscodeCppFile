#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll n,m;
int visit[MAXN];
void solve()
{
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n;i++) visit[i]=0;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        visit[b]=1;
    }
    int id;
    for(int i=1;i<=n;i++)
    {
        if(visit[i]==0) 
        {
            id=i;
            break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i==id) continue;
        cout<<i<<" "<<id<<endl;
    }
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