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
ll a[MAXN],tt,stk[MAXN];
ll l[MAXN],r[MAXN];//向左延伸和向右延伸的最大数量
void solve()
{
    n=read();
    rep(i,1,n) a[i]=read();
    rep(i,1,n)
    {
        while(tt&&a[stk[tt]]<a[i])
        {
            tt--;

        }
    }
    
}

int main()
{
    solve();
    return 0;
}