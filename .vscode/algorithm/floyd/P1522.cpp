#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 205
typedef pair<int,int> pii;
#define xx first
#define yy second
#define INF 1e12
char s[MAXN][MAXN];
double dis[MAXN][MAXN];
pii p[MAXN];//存储坐标
ll n;
double mxd[MAXN];//与每个点连通的最远的距离
double get(pii a,pii b)
{
    double dx=abs(a.xx-b.xx)+0.0;
    double dy=abs(a.yy-b.yy)+0.0;
    return sqrt(dx*dx+dy*dy);
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].xx>>p[i].yy;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>s[i]+1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[i][j]=='0') dis[i][j]=INF;
            else if(s[i][j]=='1') dis[i][j]=get(p[i],p[j]);
        }
    }
    //计算多源最短路
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=1;i<=n;i++)
    {
        double mx=0;
        for(int j=1;j<=n;j++)
        {
            if(i==j||dis[i][j]>=INF) continue;
            mx=max(mx,dis[i][j]);
        }
        mxd[i]=mx;
    }
    double ans1=0;
    for(int i=1;i<=n;i++)
        ans1=max(ans1,mxd[i]);
    double ans2=INF;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            if(dis[i][j]>=INF) 
            ans2=min(ans2,mxd[i]+mxd[j]+get(p[i],p[j]));
        }
    }
    printf("%.6lf",max(ans1,ans2));
}

int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}