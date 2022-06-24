#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 2000005
typedef pair<ll,ll> pll;
#define xx first
#define yy second
ll n;
pll a[MAXN];
ll r[MAXN];//一个左端点能达到的最优端点
ll sum[MAXN];//以i为右端点的区间的个数
void solve()
{
    cin>>n;
    vector <ll> v;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i].xx>>a[i].yy;
        v.emplace_back(a[i].xx);
        v.emplace_back(a[i].yy);
    }
    //离散化端点值
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=0;i<v.size();i++) 
    {
        sum[i]=0;r[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        a[i].xx=lower_bound(v.begin(),v.end(),a[i].xx)-v.begin()+1;
        a[i].yy=lower_bound(v.begin(),v.end(),a[i].yy)-v.begin()+1;
        r[a[i].xx]=max(r[a[i].xx],a[i].yy);//存储a[i].xx对应的最右边能到达的端点
    }
    sort(a+1,a+1+n);
    //正式处理
    int now=0;
    int ans=1;//需要保存下来的区间数量
    int pos=1;//当前遍历到的位置
    for(int i=0;i<(int)v.size();i++)//遍历左端点
    {
        now-=sum[i-1];//下界向右移动，以原先下界为上界的区间要删除
        while(pos<=n)
        {
            if(a[pos].xx<=r[i])//如果pos能塞入当前区间
            {
                sum[a[pos].yy]++;
                pos++;
                now++;
            }
            else
            break;
        }
        ans=max(ans,now);
    }
    cout<<n-ans<<endl;
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