#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
ll a[MAXN];
ll l_cnt[MAXN];ll r_cnt[MAXN];
ll n,l,r;
void solve()
{
    cin>>n>>l>>r;
    ll ans=0;
    for(int i=1;i<=n;i++) 
    {
        l_cnt[i]=0;r_cnt[i]=0;
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(i<=l) l_cnt[a[i]]++;
        else r_cnt[a[i]]++;
    }
    for(int i=1;i<=n;i++)//把能匹配的都先处理好
    {
        ll minx=min(l_cnt[i],r_cnt[i]);
        l-=minx;r-=minx;
        l_cnt[i]-=minx;r_cnt[i]-=minx;
    }
    if(l<r)
    {
        swap(l,r);
        swap(l_cnt,r_cnt);       
    }
    //此时l和r表示左边不能匹配的数的数量和右边不能匹配的数的数量
    for(int i=1;i<=n;i++)//现在只是单纯的把左右换一下
    {
        ll dx=l-r;
        ll x=min(dx,l_cnt[i]-(l_cnt[i]%2));//min(dx/2,l_cnt[i]),保证减去的一定是偶数
        l-=x;//l-=x/2;r+=x/2;
        ans+=x/2;
    }
    //现在剩下的都是颜色不能匹配，左右不能匹配的,既要换左右又要换颜色
    ans+=(l-r)/2+(l+r)/2;
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