#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define MAXN 200005
typedef pair<ll,ll> pll;
ll a[MAXN];ll n,m,k;
//m元组的最大值与最小值只差<=k
ll binary_search(int x)//找小于等于x的最大位置
{
    int l=1;int r=n;
    ll ans=n;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(a[mid]<=x) 
        {
            ans=mid;
            l=mid+1;
        }
        else if(a[mid]>x) r=mid-1;
        
    }
    return ans;
}

ll quickpow(ll a,ll n)
{
    ll ans=1;
    while(n)
    {
        if(n%2)
        {
            n--;
            ans=(ans*a)%mod;
        }
        else
        {
            n/=2;
            a=(a*a)%mod;
        }
    }
    return ans;
}

ll combination(ll n,ll m)//C_n^m
{
    if(m==0) return 1;
    if(m>n-m) m=n-m;
    ll up=1;ll down=1;
    for(int i=1;i<=m;i++)
    {
        up=(up*(n-i+1))%mod;
        down=(down*i)%mod;
    }
    return up*quickpow(down,mod-2)%mod;
}

void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    //for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    //cout<<endl;
    //a[j]-a[i]<=k
    //a[j]<=a[i]+k
    ll cnt=0;
    for(int i=1;i<=n;i++)
    {
        int now=a[i]+k;//要找的上界
        ll pos=binary_search(now);
        //C_{pos-i}^m
        //cout<<"i: "<<i<<" pos: "<<pos<<" cnt: "<<max(0ll,combination(pos-i,m-1))<<endl;
        if(pos-i>=m-1)
        cnt=(cnt+max(0ll,combination(pos-i,m-1)))%mod;
    }
    cout<<cnt<<endl;
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