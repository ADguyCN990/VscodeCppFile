#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
#define N 1000000
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int n,k;
int a[MAXN];
int prime[1000005];
int isprime[1000005];

void pre()//素数筛
{
    for(int i=2;i<=N;i++)
    {
        if(!prime[i]) prime[++prime[0]]=i,isprime[i]=1;
        for(int j=1;j<=prime[0]&&prime[j]<=N/i;j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}

void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        if(!isprime[a[i]]) continue;//不是素数
        int now=i+k;
        ll cnt1=0;
        ll cnt2=0;
        while(now<=n)
        {
            if(a[now]!=1) break;
            cnt1++;
            now+=k;
        }
        now=i-k;
        while(now>0)
        {
            if(a[now]!=1) break;
            cnt2++;
            now-=k;
        }
        ans+=(cnt1+1)*(cnt2+1)-1;
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