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
ll b[MAXN];
void solve()
{
    n=read();
    rep(i,1,n) a[i]=read();
    sort(a+1,a+1+n);
    int cnt=0;
    int pos=1;
    for(int i=2;i<=n;i+=2)
    {
        b[i]=a[pos++];
    }
    for(int i=1;i<=n;i+=2)
    {
        b[i]=a[pos++];
    }
    rep(i,1,n)
    {
        if(b[i]<b[i-1]&&b[i]<b[i+1])
            cnt++;
    }
    cout<<cnt<<endl;
    rep(i,1,n) cout<<b[i]<<" ";
}

int main()
{
    solve();
    return 0;
}