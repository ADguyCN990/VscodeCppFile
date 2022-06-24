#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 3005
ll n;
ll a[MAXN];
ll sum[MAXN];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    vector <ll> div;//所有能被整除的因子
    for(int i=1;i*i<=sum[n];i++)
    {
        if(sum[n]%i==0) 
        {
            if(i*i==sum[n]) 
                div.emplace_back(i);
            else 
            {
                div.emplace_back(i);
                div.emplace_back(sum[n]/i);
            }
        }
    }
    int min_cnt=n-1;
    for(auto now:div)
    {
        //要求所有区间和为now
        int flag=1;//标记这样构造合不合法
        int i=1;//下界
        int j=1;//上界
        int cnt=0;
        while(j<=n)
        {
            ll dx=sum[j]-sum[i-1];
            if(sum[j]-sum[i-1]<now)
            {
                j++;
                cnt++;
                if(j==n+1)
                {
                    flag=0;
                    break;
                }
            }
            if(sum[j]-sum[i-1]==now)
            {
                i=j+1;
                j++;
            }
            else if(sum[j]-sum[i-1]>now)
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
            min_cnt=min(min_cnt,cnt);
    }
    cout<<min_cnt<<endl;
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