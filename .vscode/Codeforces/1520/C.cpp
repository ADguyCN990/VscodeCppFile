#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
ll n;
void solve()
{
    cin>>n;
    if(n==1) 
    {
        cout<<1<<endl;
        return;
    }
    if(n==2)
    {
        cout<<-1<<endl;
        return;
    }
    int mp[MAXN][MAXN];
    int cnt=1;
    for(int i=1;i<=n;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=n;j+=2)
            {
                mp[i][j]=cnt++;
            }
        }
        else 
        {
            for(int j=2;j<=n;j+=2)
            {
                mp[i][j]=cnt++;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i%2==1)
        {
            for(int j=2;j<=n;j+=2)
            {
                mp[i][j]=cnt++;
            }
        }
        else 
        {
            for(int j=1;j<=n;j+=2)
            {
                mp[i][j]=cnt++;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<mp[i][j]<<' ';
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