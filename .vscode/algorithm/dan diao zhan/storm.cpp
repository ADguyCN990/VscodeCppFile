#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
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
ll stk[MAXN],tt;//栈中存放的是下标，不是元素，单调递增栈
ll l[MAXN],r[MAXN];
void solve()
{
    rep(i,1,n) a[i]=read(),l[i]=0,r[i]=0;
    ll ans=0;
    rep(i,1,n)
    {
        while(tt&&a[stk[tt]]>a[i]) 
        {
            int now=stk[tt];
            r[now]=i-1;
            tt--;
        }
        l[i]=stk[tt]+1;
        stk[++tt]=i;
    }
    while(tt)
    {
        r[stk[tt]]=n;
        tt--;
    }
    rep(i,1,n)
    {
        ans=max(ans,a[i]*(r[i]-l[i]+1));
    }
    printf("%lld\n",ans);
}

int main()
{
    while(scanf("%d",&n))
    {
        if(n==0) break;
        solve();
    }

    return 0;
}