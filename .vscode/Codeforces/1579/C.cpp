#include<bits/stdc++.h>
using namespace std;
#define MAXN 25
#define ll long long
char mp[MAXN][MAXN];
int f[MAXN][MAXN];
int t;
int n,m,k;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>mp[i][j];
                if(mp[i][j]=='*') f[i][j]=1;
                else f[i][j]=0;            
            }
        }
        
        for(int i=n;i>0;i--)//倒着往上找
        {
            for(int j=1;j<=m;j++)
            {
                if(f[i][j]==0) continue;
                int len=0;
                while(j>len&&i>len&&j+len<=m)//在边界范围内
                {
                    if(f[i-len-1][j-len-1]==0||f[i-len-1][j+len+1]==0)
                    {
                       break;
                    }
                    len++;
                }
                if(len>=k) 
                for(int x=0;x<=len;x++)
                {
                    f[i-x][j+x]=2;f[i-x][j-x]=2;
                }
            }
        }
        int ok=1;
        // for(int i=1;i<=n;i++)
        // {
        //     for(int j=1;j<=m;j++)
        //     {
        //         cout<<"__"<<f[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(f[i][j]==1)
                {
                    ok=0;
                    break;
                }
            }
        }
        if(ok) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    

    return 0;
}

