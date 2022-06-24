#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
ll n;
ll a[MAXN];
void solve()
{
    n=read();
    int cnt=0;
    rep(i,1,n)
    {
        a[i]=read();
        if(a[i]<0) cnt++;
    }
    sort(a+1,a+1+n);
    ll mx=1;
    per(i,n,n-4) mx=mx*a[i];
    if(cnt>=2)
        mx=max(mx,a[1]*a[2]*a[n]*a[n-1]*a[n-2]);
    if(cnt>=4)
    {
        mx=max(mx,a[1]*a[2]*a[3]*a[4]*a[n]);
    }
    cout<<mx<<endl;
}

int main()
{
    int T;
    T=read();
    while(T--)
    {
        solve();
    }

    return 0;
}