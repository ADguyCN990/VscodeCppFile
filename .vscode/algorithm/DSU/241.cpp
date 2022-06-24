#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 20005
int n,m,ans;
int f[MAXN];
unordered_map <int,int> mp;//离散化用
int dis[MAXN];

int gethash(int x)
{
    if(!mp.count(x)) mp[x]=++n;
    return mp[x];
}

int findx(int x)
{
    if(x!=f[x])
    {
        int t=f[x];
        f[x]=findx(f[x]);
        dis[x]^=dis[t];
    }
    return f[x];
}

void solve()
{
    cin>>n>>m;
    n=0;//让n作为离散化后的数据个数
    ans=m;
    for(int i=1;i<=20000;i++) f[i]=i;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        string st;
        cin>>a>>b>>st;
        a=gethash(a-1),b=gethash(b);//前缀和
        //sum[b]-sum[a-1]中是奇数还是偶数个1
        //偶数表示两个相同，奇数表示两个相反
        //1代表奇数表示不同，0代表偶数表示相同，因为异或
        int t=0;
        if(st=="odd")
            t=1;
        int fx=findx(a),fy=findx(b);
        if(fx==fy)//之前已经在同一集合维护过关系
        {
            if((dis[a]^dis[b])!=t)
            {
                ans=i-1;//当前回合失败，答案为前一回合
                break;
            }
        }
        else
        {
            f[fy]=fx;
            dis[fy]=dis[a]^dis[b]^t;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}