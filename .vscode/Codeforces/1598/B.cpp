#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
int a[MAXN][10];
int t,n;
void solve()
{
    cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=5;j++)
            {
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=4;i++)
        {
            for(int j=i+1;j<=5;j++)
            {
                int cnt_i=0,cnt_j=0;
                int flag=1;
                for(int k=1;k<=n;k++)
                {
                    if(a[k][i]==0&&a[k][j]==0)
                    {
                        flag=0;
                        break;
                    }
                    else if(a[k][i]==1&&a[k][j]==0)
                    {
                        cnt_i++;
                    }
                    else if(a[k][i]==0&&a[k][j]==1)
                    {
                        cnt_j++;
                    }
                }
                if(flag==1&&cnt_i<=n/2&&cnt_j<=n/2)
                {
                    cout<<"Yes"<<endl;
                    return;
                }
            }
        }
        cout<<"No"<<endl;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}