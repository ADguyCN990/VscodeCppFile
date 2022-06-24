#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 25
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int n,m;//n表示体积，m表示层数
int mins[MAXN],minv[MAXN];//前i层的最小表面积和前i层的最小体积
int ans=INF;
int R[MAXN],H[MAXN];//上一层的半径，上一层的高

void dfs(int now,int v,int s)//当前的层数，当前的体积，当前的表面积
{
    if(v+minv[now]>n) return;
    if(s+mins[now]>=ans) return;
    if(s+2*(n-v)/R[now+1]>=ans) return;

    if(!now)
    {
        if(v==n) ans=s;
        return;
    }

    for(int r = min(R[now + 1] - 1,(int)sqrt((n - v - minv[now - 1]) / now)); r >= now; r--)
        for(int h = min(H[now + 1] - 1, (n - v - minv[now - 1]) / r / r); h >= now; h--)
        {
            H[now] = h, R[now] = r;//记录

            //最底层的时候需要加上r*r
            int t=0;
            if(now==m) t=r*r;

            dfs(now - 1, v + r * r * h, s + 2 * r * h + t);
        }


}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        mins[i]=mins[i-1]+2*i*i;
        minv[i]=minv[i-1]+i*i*i;
    }
    mins[m+1]=INF,minv[m+1]=INF;
    R[m+1]=INF,H[m+1]=INF;
    dfs(m,0,0);
    if(ans==INF) cout<<0<<endl;
    else cout<<ans<<endl;

}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}