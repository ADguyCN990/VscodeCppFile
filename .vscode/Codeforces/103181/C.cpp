#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
typedef pair<double,double> pii;

int n,m,k;
pii p[MAXN];
int f[MAXN+10];

int findx(int x)
{
    if(x==f[x]) return x;
    else return f[x]=findx(f[x]);
}

bool check(double mid)
{
    for(int i=1;i<=k+4;i++) f[i]=i;
    for(int i=1;i<=k;i++)
    {
        if(m-p[i].second<mid)
        {
            int u=findx(i);
            int v=findx(k+1);
            if(u!=v) f[u]=v;
        }
        if(p[i].second<mid)
        {
            int u=findx(i);
            int v=findx(k+2);
            if(u!=v) f[u]=v;
        }
        if(n-p[i].first<mid)
        {
            int u=findx(i);
            int v=findx(k+4);
            if(u!=v) f[u]=v;
        }
        if(p[i].first<mid)
        {
            int u=findx(i);
            int v=findx(k+3);
            if(u!=v) f[u]=v;
        }
        for(int j=1;j<i;j++)
        {
            double dis=(p[i].first-p[j].first)*(p[i].first-p[j].first)+(p[i].second-p[j].second)*(p[i].second-p[j].second);
            if(dis<4*mid*mid)
            {
                int u=findx(i);
                int v=findx(j);
                if(u!=v) f[u]=v;
            }
                
        }
    }
    //cout<<"mid: "<<mid<<endl;
    //cout<<findx(k+1)<<" "<<findx(k+2)<<" "<<findx(k+3)<<" "<<findx(k+4)<<endl;
    if(findx(k+1)==findx(k+2)||findx(k+3)==findx(k+4)||findx(k+1)==findx(k+4)||findx(k+3)==findx(k+2)) return false;
	return true;
}

void solve()
{
    scanf("%d%d",&n,&m);
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
        scanf("%lf%lf",&p[i].first,&p[i].second);
    double l=0,r=max(n,m);
    while(r-l>1e-6)
    {
        double mid=(l+r)/2.0;
        if(check(mid))
        {
            l=mid;
        }
        else
            r=mid;
    }
    printf("%.6lf\n",l);
}

int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}