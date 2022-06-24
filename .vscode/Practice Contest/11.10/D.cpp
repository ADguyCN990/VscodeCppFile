#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
map <ll,ll> mp;
typedef pair<ll,ll> pll;
ll get(ll x,ll y)
{
    ll t;
    cout<<x<<" "<<y<<endl;
    cout.flush();
    cin>>t;
    return t;
}

void pre()
{
    for(ll i=0;i<=1000000;i++)
        mp[i*i]=1;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    pre();
    cin>>n;
    int cnt=0;
    while(cnt<n)
    {
        ll dis=get(0,0);//距离的平方
        if(dis==0)
        {
            cnt++;
            continue;
        }
        vector <pll> v;
        for(ll x=0;x*x<=dis;x++)
        {
            ll y=sqrt(dis-x*x);
            if(mp[dis-x*x]==0)
                continue;
            v.emplace_back(x,y);
        }
        for(auto now:v)
        {
            ll x=now.first;
            ll y=now.second;
            ll d=get(x,y);
            if(d==0)
            {
                cnt++;
                break;
            }
        }
    }

    return 0;
}