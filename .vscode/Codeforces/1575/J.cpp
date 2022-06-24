#include<bits/stdc++.h>
using namespace std;
#define MAXN 1005
#define ll long long
int mp[MAXN][MAXN];
int visit[MAXN][MAXN];
//1向右，2向下，3向左
//如果之前访问过，那么一定是向下
int n,m,k;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>mp[i][j];
        }
    }
    while(k--)
    {
        int x=1;int y;
        cin>>y;
        while(x<=n)
        {
            int xx=x;int yy=y;
            if(mp[x][y]==1)
            {
                y++;
            }
            else if(mp[x][y]==2)
            {
                x++;
            }
            else
            {
                y--;
            }
            if(visit[xx][yy]==0)
            {
                visit[xx][yy]=1;
                mp[xx][yy]=2;
            }
        }  
        cout<<y<<" ";   
    }

    return 0;
}