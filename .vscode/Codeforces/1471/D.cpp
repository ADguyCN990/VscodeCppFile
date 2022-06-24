#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long
#define MAXN 300005
#define N 1e6
int prime[(ll)N+10];
ll a[MAXN];
ll ans1,ans0,n;
map <ll,ll> mp;//哈希值出现的次数
vector <ll> v;//存放所有的哈希值
void getprime()
{
    for(int i=2;i<=N;i++)
    {
        if(!prime[i]) prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<=N/i;j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}
void getfactor(ll x)
{
    int fatcnt=0;
    ll factor[1005][2];//0表示具体数值，1表示因子个数
    ll tmp=x;
    ll hash=1;
    for(int i=1;prime[i]<=tmp/prime[i];i++)
    {
        factor[fatcnt][1]=0;
        if(tmp%prime[i]==0)
        {
            factor[fatcnt][0]=prime[i];
            while(tmp%prime[i]==0)
            {
                factor[fatcnt][1]++;
                tmp/=prime[i];
            }
            if(factor[fatcnt][1]%2==1)
                hash*=factor[fatcnt][0];
            fatcnt++;
        }
    }
    if(tmp!=1)
    {
        factor[fatcnt][0]=tmp;
        factor[fatcnt][1]=1;
        hash*=tmp;
    }
    v.emplace_back(hash);
    ans0=max(ans0,++mp[hash]);
    //cout<<"hash for "<<x<<" : "<<hash<<endl;
}

void init()
{
    ans1=0;ans0=0;
    v.clear();mp.clear();
}

void solve()
{
    init();
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        getfactor(a[i]);
    }
    ll even=0;
    for(auto now:v)
    {
        if(now!=1&&mp[now]%2==0) even++;//经历一次变化后，偶数个奇数相加，原本为奇数的指数变成了偶数，偶数依旧是偶数，相当于变成了1
        else if(now==1) ans1++;//原本就是1
    }
    //cout<<ans0<<" "<<ans1<<" "<<even<<endl;
    int q;
    cin>>q;
    while(q--)
    {
        ll t;
        cin>>t;
        if(t==0) cout<<ans0<<endl;
        else cout<<max(ans0,ans1+even)<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    getprime();
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}