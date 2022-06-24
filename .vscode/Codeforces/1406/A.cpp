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
int vis[105];
void solve()
{
    n=read();
    memset(vis,0,sizeof vis);
    ll mx=0;
    int start=0;
    int flag=1;
    rep(i,1,n) 
    {
        ll tmp;
        tmp=read();
        vis[tmp]++;
    }
    rep(i,0,100) 
    {
        if(!vis[i]) 
        {
            mx=i;
            break;
        }
        if(vis[i]>=2&&flag)
        {
            start=i+1;
        }
        else
            flag=0;
    }
    cout<<mx+start<<endl;
    
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