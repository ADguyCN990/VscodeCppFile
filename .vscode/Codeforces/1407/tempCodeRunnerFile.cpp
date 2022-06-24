#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 10005
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

ll get(ll x,ll y)
{
    printf("? %lld %lld\n",x,y);
    cout.flush();
    ll ans;
    ans=read();
    return ans;
}

ll n;
int b[MAXN];
int a[MAXN];
int mx=1;//n的下标
int mxid;
void solve()
{
    n=read();
    rep(i,2,n)
    {
        int x=get(mx,i);
        int y=get(i,mx);
        if(y<x)
            mx=i;
    }
    a[mx]=n;
    rep(i,1,n)
    {
        if(i==mx) continue;
        a[i]=get(i,mx);
    }
    printf("! ");
    cout.flush();
    rep(i,1,n)
    {
        printf("%lld ",a[i]);
        cout.flush();
    }
}

int main()
{
    solve();
    return 0;
}