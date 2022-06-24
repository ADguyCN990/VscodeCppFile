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
ll a,b,x,y,n;
void solve()
{
    a=read(),b=read(),x=read(),y=read(),n=read();
    if(a>b) swap(a,b),swap(x,y);
    //先减a再减b
    ll dx=a-x;
    if(dx>=n)
    {
        a-=n;
        printf("a: %d b: %d\n",a,b);
        printf("%lld\n",a*b);
        return;
    }
    a=x;
    n-=dx;
    b-=min(n,b-y);
    printf("a: %d b: %d\n",a,b);
    printf("%lld\n",a*b);
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