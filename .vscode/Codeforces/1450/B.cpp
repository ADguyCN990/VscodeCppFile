#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
int x[MAXN];
int y[MAXN];
ll n,k;
//在一个平面中，有很多小球，给定一个吸引力常数 k k k。现在你可以进行若干操作。操作为：每次选取一个小小球使其带电，之后所有与该点相距小于 k k k的会被吸引过去。问你要进行多少的操作次数使得所有小球的坐标相同。
ll get(int i,int j)
{
    return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    for(int i=1;i<=n;i++)
    {
        int flag=1;
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            if(get(i,j)>k)
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            cout<<"1"<<endl;
            return;
        }
    }
    
    cout<<-1<<endl;
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