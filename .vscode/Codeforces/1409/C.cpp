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
ll n,x,y;

void solve()
{
    n=read(),x=read(),y=read();
    ll dx=y-x;
    rep(i,1,dx)
    {
        if(dx%i) continue;
        if(dx/i+1>n) continue;
        int k=min(n-1,(y-1)/i);//前者对应y是最大值，且已保证能取到x；后者则为y不是最大值
        int start=y-k*i;
        for(int j=start,cnt=1;cnt<=n;j+=i,cnt++)
        {
            printf("%d ",j);
        }
        puts("");
        break;
    }
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