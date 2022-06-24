#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
ll a[MAXN];
ll sum[MAXN];
ll n,k;
pii ans;

void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    ans={-1,1};
    ll l=1;
    ll mx=0;//最大的长度
    ll sum=0;//当前和的大小
    ll len=0;//当前的长度
    for(int r=1;r<=n;r++)//尺取法枚举右端点
    {
        //右移时更新len，sum
        len++;
        sum+=a[r];
        while(l<=r&&sum<0&&abs(sum)>k)
        {
            sum-=a[l++];
            len--;
        }
        if(len>mx)
        {
            mx=len;
            ans=pii{l,r};
        }
    }
    if(ans==pii{-1,1}) cout<<-1<<endl;
    else cout<<ans.first<<" "<<ans.second<<endl;
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