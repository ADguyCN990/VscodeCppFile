#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
int sx,sy,ex,ey;

double get(double x,double y,double xx,double yy)
{
    return sqrt(abs(x-xx)*abs(x-xx)+abs(y-yy)*abs(y-yy));
}

void solve()
{
    cin>>sx>>sy;
    double dis=0;
    double x,y,xx,yy;
    while(cin>>x>>y>>xx>>yy)
    {
        dis+=get(x,y,xx,yy);
    }
    int minutes=round(dis*2/1000*3);
    int h=minutes/60;
    int m=minutes%60;
    printf("%d:%02d\n",h,m);
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}