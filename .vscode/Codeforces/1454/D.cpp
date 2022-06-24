#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
bool is_prime(ll n)
{
    if(n==2) return false;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0) return true;
    }
    return false;
}

ll quickpow(ll a,ll n)
{
    ll ans=1;
    while(n)
    {
        if(n%2==0)
        {
            n/=2;
            a*=a;
        }
        else if(n%2==1)
        {
            n--;
            ans*=a;
        }
    }
    return ans;
}

void solve()
{
    cin>>n;
    ll N=n;
    if(is_prime(n)==false)
    {
        cout<<1<<endl<<n<<endl;
        return;
    }
    vector <int> factor;
    for(ll i=2;i<=sqrt(n);i++)
    {      
        while(n%i==0)
        {
            factor.emplace_back(i);
            n/=i;
        }
    }
    if(n>1) factor.emplace_back(n);
    int i=0;
    int len=factor.size();
    if(len==2&&factor[1]%factor[0]!=0)
    {
        cout<<1<<endl<<N<<endl;
        return;
    }
    int mx=0;//数字
    int cnt=0;//个数
    while(i<len)
    {
        int num=upper_bound(factor.begin(),factor.end(),factor[i])-lower_bound(factor.begin(),factor.end(),factor[i]);
        if(num>cnt)
        {
            mx=factor[i];
            cnt=num;
        }
        i+=num;
    }
    cout<<cnt<<endl;
    for(int i=1;i<cnt;i++) cout<<mx<<" ";
    cout<<N/quickpow(mx,cnt-1)<<endl;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }

    return 0;
}