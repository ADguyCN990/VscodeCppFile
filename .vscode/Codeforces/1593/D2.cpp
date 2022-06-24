#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 45
ll n;
ll a[MAXN];
vector <ll> factor;//记录差值的因子数，然后直接暴力判断符不符合题意
ll gcd(ll x,ll y)
{
    ll temp;
    if(x<y) swap(x,y);
    while(y)
    {
        temp=y;
        y=x%y;
        x=temp;
    }
    return x;
}

void solve()
{
    cin>>n;//n为偶数
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        if(count(a+1,a+1+n,a[i])>=(n+1)/2)  //3 7
        {
            cout<<-1<<endl;
            return;
        }
    }
    //前面一段是特判，从这开始正式处理
    //暴力求出所有差值的所有因子
    factor.clear();
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            ll dx=a[j]-a[i];
            for(int k=1;k*k<=dx;k++)
            {
                if(dx%k==0)
                {
                    factor.emplace_back(k);
                    factor.emplace_back(dx/k);
                }
            }
        }
    }
    //去重+降序
    sort(factor.begin(),factor.end());   
    factor.erase(unique(factor.begin(),factor.end()),factor.end());
    reverse(factor.begin(),factor.end());
    //最少n/2个数，需要n/2-1个差值的因子中包含x
    for(auto x:factor)//因子
    {
        for(int i=1;i<=n;i++)
        {
            int cnt=0;
            for(int j=i+1;j<=n;j++)
            {
                if((a[j]-a[i])%x==0)
                {
                    cnt++;
                }
                if(cnt>=n/2-1)
                {
                    cout<<x<<endl;
                    return;
                }
            }
        }
    }
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