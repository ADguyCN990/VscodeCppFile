#include<bits/stdc++.h>
using namespace std;
#define MAXN 405
#define ll long long
ll n,m;
ll cnt[MAXN][MAXN];//二维前缀和，记录1的个数
int a[MAXN][MAXN];
void build()
{
    cin>>n>>m;
    cnt[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char c;
            cin>>c;
            int now=c-'0';
            a[i][j]=now;
            cnt[i][j]=cnt[i-1][j]+cnt[i][j-1]-cnt[i-1][j-1]+now;
        }
    }
}
ll cal(int x,int y,int xx,int yy)
{
    return cnt[xx][yy]-cnt[xx][y-1]-cnt[x-1][yy]+cnt[x-1][y-1];
}
void solve()
{
    build();
    //上下左右得是1,翻转0；中间得是0，翻转1
    ll ans=0x3f3f3f3f;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+4;j<=n;j++)
        {
            int mn=0x3f3f3f3f;
            for(int x=m-3;x>=1;x--)
            {
                int h=j-i+1;
                int up=2-cal(i,x+1,i,x+2);
                int down=2-cal(j,x+1,j,x+2);
                int left=h-2-cal(i+1,x,j-1,x);
                int mid=cal(i+1,x+1,j-1,x+2);
                ll half=up+down+left+mid;
                mn=min(mn+!a[i][x+3]+!a[j][x+3]+cal(i+1,x+3,j-1,x+3),h-2-cal(i+1,x+3,j-1,x+3));//并入肚皮或者作为边界
                ans=min(ans,mn+half);
            }
        }
    }
    cout<<ans<<endl;
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