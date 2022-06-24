#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
typedef pair <ll,ll> pll;
ll n;
ll a[MAXN];
//三元组的最大值减去其对应的最小值<=2,输出这种三元组的个数

int binary_search(int x)//找小于等于x的最大位置
{
    int l=1;int r=n;
    int ans=n;
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

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    //a[j]-a[i]<=2
    //a[j]<=a[i]+2
    ll cnt=0;
    for(int i=1;i<=n;i++)
    {
        int now=a[i]+2;//要找的上界
        int pos=binary_search(now);
        cnt+=max(0ll,ll((pos-i-1)*(pos-i)/2));
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