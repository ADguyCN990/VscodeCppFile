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
ll n;
ll a[MAXN];
ll d[MAXN];

void update(int l,int r,int x)
{
    d[l]+=x;
    d[r+1]-=x;
}

void solve()
{
    n=read();
    rep(i,1,n) a[i]=read();
    rep(i,1,n) d[i]=a[i]-a[i-1];
    //rep(i,1,n) printf("%lld ",d[i]);
    ll cnt=0;
    ll mx=0;
    ll ans=0;
    rep(i,2,n) 
    {
        if(d[i]>0)
            cnt+=d[i];
        
    }
   

}

int main()
{
    solve();
    return 0;
}