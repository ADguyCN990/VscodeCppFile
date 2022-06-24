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
ll a[MAXN];
ll b[MAXN];
ll n;
void solve()
{
    n=read();
    for(int i=1;i<=n+1;i++)
    {
        a[i]=read();
    }
    for(int i=1;i<=n+1;i++)
    {
        b[i]=read();
    }
    ll ans=0;
    for(int i=n+1;i>=2;i--)
    {
        if(b[i]<=a[i]) continue;
        ll need=(b[i]-a[i]+1)/2;
        a[i]+=need*2;
        a[i-1]-=need;
        ans+=need;
    }
    if(a[1]>=b[1])
    {
        cout<<ans<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}