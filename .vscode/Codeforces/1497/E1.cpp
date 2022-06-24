#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define N 10000005
ll n;
ll a[MAXN];
ll factor[10005][2];//factor[i][0]存放具体的因数值，factor[i][1]存放因数的个数
int fatcnt;
int k;
map <int,int> mp;
int prime[N];
void pre()//帅选出1e7以内的所有质数
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
ll getfactors(ll x)
{
    ll sum=1;
    fatcnt=0;
    ll temp=x;
    for(int i=1;prime[i]<=temp/prime[i];i++)
    {
        factor[fatcnt][1]=0;
        if(temp%prime[i]==0)
        {
            factor[fatcnt][0]=prime[i];
            while(temp%prime[i]==0)
            {
                factor[fatcnt][1]++;
                temp/=prime[i];
            }
            if(factor[fatcnt][1]%2==1)//分解质因数后这个质数的幂为奇数次
            {
                sum=sum*prime[i];
            }
            fatcnt++;            
        }
    }
    return sum*temp;
}

void solve()
{
    mp.clear();
    cin>>n>>k;
    int ans=1;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        ll now=getfactors(a[i]);
        if(mp.count(now))
        {
            ans++;
            mp.clear();
        }
        mp[now]++;
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    pre();
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}