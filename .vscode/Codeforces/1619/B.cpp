#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define pb emplace_back
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
ll gcd(ll a,ll b)
{
    if(a<b) swap(a,b);
    ll tmp;
    while(b)
    {
       tmp=b;
       b=a%b;
       a=tmp; 
    }
    return a;
}
vector <ll> v;
void solve()
{
    ll n;
    n=read();
    ll it=upper_bound(v.begin(),v.end(),n)-v.begin();
    cout<<it<<endl;
    

}
int main()
{
    int T;
    T=read();
    rep(i,1,1000)
    {
        v.pb(i*i*i);
    }
    rep(i,1,31622)
    {
        v.pb(i*i);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    while(T--)
    {
        solve();
    }

    return 0;
}