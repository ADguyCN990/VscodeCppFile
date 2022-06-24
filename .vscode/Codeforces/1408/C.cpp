#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int n,k;
int a[MAXN];
long double dp1[MAXN];//正向时间
long double dp2[MAXN];//反向时间
void solve()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    a[n+1]=k;dp1[0]=0,dp2[n+1]=0;
    dp1[1]=(long double)a[1];
    for(int i=2;i<=n+1;i++)
    {
        dp1[i]=dp1[i-1]+(long double)(a[i]-a[i-1])/i;
    }
    dp2[n]=(long double)(k-a[n]);

    for(int i=n-1;i>=0;i--)
    {
        dp2[i]=dp2[i+1]+(long double)(a[i+1]-a[i])/(n-i+1);
    }
    for(int i=1;i<=n;i++)
    {
        if(dp1[i]==dp2[i])
        {
            printf("%.10Lf\n",dp1[i]);
            return;
        }
    }
    for(int i=0;i<=n;i++)
    {
        if(dp1[i+1]<=dp2[i]&&dp1[i+1]>=dp2[i+1]||dp2[i]>=dp1[i]&&dp2[i]<=dp1[i+1])
        {
            if(dp1[i]<dp2[i+1])
            {
                long double v1=i+1,v2=n-i+1;
                long double s=a[i+1]-a[i]-v1*(dp2[i+1]-dp1[i]);
                long double t=s/(v1+v2)+dp2[i+1];
                printf("%.10Lf\n",t);
                return;
            }
            else
            {
                long double v1=i+1,v2=n-i+1;
                long double s=a[i+1]-a[i]-v2*(dp1[i]-dp2[i+1]);
				long double t=s/(v1+v2)+dp1[i];
                printf("%.10Lf\n",t);
                return;
            }
        }
    }
}

int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }

    return 0;
}