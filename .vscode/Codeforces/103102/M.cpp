#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 500005
#define MAXM 250005
int n,m,k;
int indgr[MAXN];
int cnt[MAXN];


void solve()
{
    cin>>n>>k>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;

    }
    for(int i=1;i<=n*k;i++)
    {
        int tmp;
        cin>>tmp;
        cnt[tmp]++;
        cout<<cnt[tmp]<<" ";
    }
    
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}