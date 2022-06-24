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
ll n,x;
ll a[MAXN];
void solve()
{
    n=read(),x=read();
    bool flag=true;
    bool f=false;
    ll sum=0;
    rep(i,1,n)
    {
        a[i]=read();
        sum+=a[i];
        if(a[i]!=x) flag=0;
        if(a[i]==x) f=true;
    }
    if(flag)
    {
        cout<<0<<endl;
        return;
    }
    if(x!=0&&sum%n==0&&sum/n==x||x==0&&sum==0)
    {
        cout<<1<<endl;
        return;
    }
    if(f)
    {
        cout<<1<<endl;
        return;
    }
    cout<<2<<endl;

}

int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    T=read();
    while(T--)
    {
        solve();
    }

    return 0;
}