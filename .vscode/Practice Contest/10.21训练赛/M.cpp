#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 505
ll n,m;
char c[MAXN][MAXN];int a[MAXN][MAXN];int b[MAXN][MAXN];

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>c[i][j];
            //cout<<c[i][j]<<" ";
        }
        //cout<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==1) 
            {
                a[i][j]=1;b[i][j]=0;
                continue;
            }
            else if(i==n)
            {
                a[i][j]=0;b[i][j]=1;
                continue;
            }
            else if(j==1)
            {
                a[i][j]=1;b[i][j]=0;
                continue;
            }
            else if(j==m)
            {
                a[i][j]=0;b[i][j]=1;
                continue;
            }
            else if(i%2==0)
            {
                a[i][j]=1;b[i][j]=0;               
            }
            else if(i%2==1)
            {
                a[i][j]=0;b[i][j]=1;               
            }
            if(c[i][j]=='1')
            {
                a[i][j]=1;b[i][j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<b[i][j];
        }
        cout<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}