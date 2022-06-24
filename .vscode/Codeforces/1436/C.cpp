#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define mod 1000000007
int n,x,pos;
//长度，数字大小，位置

ll A(ll n,ll m)
{
	ll ans=1;
	for(ll i=n;i>=n-m+1;i--)
		ans=(ans*i)%mod;
	return ans;
}

void solve()
{
    cin>>n>>x>>pos;
    int cntl=0;int cntr=0;
    int l=0,r=n;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(mid<=pos)
        {
            l=mid+1;
            if(mid<pos)
                cntl++;
        }
        else
        {
            r=mid;
            cntr++;
        }
    }
    //cntl个数要比x小，cntr个数要比x大
    int x1=x-1;//比x小的个数
    int x2=n-x;//比x大的个数
    //cout<<x1<<" "<<x2<<" "<<cntl<<" "<<cntr<<endl;
    ll ans=A(x1,cntl)%mod*A(x2,cntr)%mod*A(n-1-cntl-cntr,n-1-cntl-cntr)%mod;
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   solve();

    return 0;
}