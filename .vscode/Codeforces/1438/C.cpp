#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
ll n,m;
ll mp[MAXN][MAXN];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>mp[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if((i+j)%2==1&&mp[i][j]%2==1)
                cout<<mp[i][j]+1;
            else if((i+j)%2==0&&mp[i][j]%2==0)
                cout<<mp[i][j]+1;
            else if((i+j)%2==1&&mp[i][j]%2==0)
                cout<<mp[i][j];
            else if((i+j)%2==0&&mp[i][j]%2==1)
                cout<<mp[i][j];
            cout<<" ";
        }
        cout<<endl;
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