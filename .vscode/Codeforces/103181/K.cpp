#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
#define mod 11451403
ll p=23333;
ll has[MAXN];
string s;
int n;
map <ll,int> mp;

ll quickpow(ll a,ll n)
{
    ll ans=1;
    while(n)
    {
        if(n%2==1)
        {
            n--;
            ans=(ans*a)%mod ;
        }
        else if(n%2==0)
        {
            n/=2;
            a=(a*a)%mod ;
        }
    }
    return ans;
}

void pre()
{
    for(int i=0;i<n;i++)
        has[i]=(has[i-1]*p+(s[i]-'A'+1))%mod;
}

ll get(int l,int r)
{
    return (has[r]-(has[l-1]*quickpow(p,r-l+1))%mod+mod)%mod;
}

bool check(int len)
{
    mp.clear();
    for(int i=0;i<n;i++)
    {
        int j=i+len-1;
        if(j>=n) break;
        mp[get(i,j)]++;
    }
    for(auto x:mp)
    {
        if(x.second==1) return true;
    }
    return false;
}

void solve()
{
    cin>>s;
    n=(int)s.length();
    pre();
    int l=1,r=n;
    int len=n;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            len=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    mp.clear();
    for(int i=0;i<n;i++)
    {
        int j=i+len-1;
        if(j>=n) break;
        mp[get(i,j)]++;
    }
    for(int i=0;i<n;i++)
    {
        int j=i+len-1;
        if(mp[get(i,j)]==1)
        {
            cout<<s.substr(i,len)<<endl;
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}