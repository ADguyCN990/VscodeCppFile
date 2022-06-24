#include<bits/stdc++.h>
using namespace std;
#define MAXN 1005
char a[MAXN][MAXN];
char b[MAXN][MAXN];
int n,m;
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
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>b[i][j];
            if(a[i][j]!=b[i][j])
                cnt++;
        }
    }
    if(cnt>n*m/2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i][j]=='.') a[i][j]='X';
                else a[i][j]='.';
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
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}