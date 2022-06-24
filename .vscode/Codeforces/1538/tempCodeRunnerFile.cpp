#include<bits/stdc++.h>
using namespace  std;
#define MAXN 200005
#define ll long long
ll a,b,c;
int t;
ll gcd(ll a,ll b)
{
    if(a<b) swap(a,b);
    while(b)
    {
        ll temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

ll get(ll x)//求x的质因子幂数之和
{
    ll ans=0;
    for(int i=2;i*i<=x;i++)
    {
        while(x%i==0)
        {
            ans++;
            x/=i;
        }
    }
    if(x>1) ans++;
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        ll gcd_ab=gcd(a,b);
        if(c==1)
        {
            if(a==b) cout<<"NO"<<endl;
            else if(gcd(a,b)==a||gcd(a,b)==b) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            continue;
        }
        ll mins,maxs;
        maxs=get(a)+get(b);
       // cout<<"geta "<<get(a)<<" getb "<<get(b)<<endl;
        if(c<=maxs) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    return 0;
}

