#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
int n,m;
int a[MAXN][MAXN];
ll ans=0;
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            vector <ll> v;
            v.emplace_back(a[i][j]);
            v.emplace_back(a[i][m-j+1]);
            v.emplace_back(a[n-i+1][j]);
            sort(v.begin(),v.end());
            ans+=(v[2]-v[0]);
            a[i][j]=a[i][m-j+1]=a[n-i+1][j]=v[1];
        }
    }
    cout<<ans<<endl;
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