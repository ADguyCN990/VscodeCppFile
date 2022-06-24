#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
ll n;
ll a[MAXN];
ll cnt[35];
ll gcd(ll a,ll b)
{
    ll temp;
    while(b)
    {
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
void solve()
{
    cin>>n;
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int f=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=0) 
        {
            f=1;break;
        }
    }
    if(f==0)
    {
        for(int i=1;i<=n;i++) cout<<i<<" ";
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        vector <int> v;
        int now=a[i];
        while(now)
        {
            int temp=now%2;
            v.emplace_back(temp);
            now/=2;
        }
        //reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++) cnt[i]+=v[i];
    }
    ll ans=-1;
    for(int i=0;i<35;i++) 
    {
        if(cnt[i]==0) continue;
        if(ans==-1) ans=gcd(cnt[i],cnt[i]);
        else
        {
            ans=gcd(ans,cnt[i]);
        }
    }
    vector <int> temp;
    for(int i=1;i<=ans;i++)
    {
        if(ans%i==0) temp.emplace_back(i);
    }
    for(auto x:temp) cout<<x<<" ";
    cout<<endl;
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