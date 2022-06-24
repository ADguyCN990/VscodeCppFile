#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
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

ll gcd(ll a,ll b)
{
    if(a<b) swap(a,b);
    ll tmp;
    while(b)
    {
       tmp=b;
       b=a%b;
       a=tmp; 
    }
    return a;
}
int n;
int a[MAXN];
int vis[MAXN];

void solve()
{
    n=read();
    rep(i,1,n) a[i]=read();
    if(n==1)
    {
        cout<<a[1]<<endl;
        return;
    }
    memset(vis,0,sizeof vis);
    sort(a+1,a+1+n,greater<long long>());
    vis[1]=1;
    vector <ll> ans;
    ans.emplace_back(a[1]);
    ll g=a[1];
    int cnt=1;
    while(g!=1)
    {
        int mx=0;
        int mxid;
        rep(i,2,n)
        {
            if(vis[i]) continue;
            ll tmp=gcd(a[i],g);
            if(tmp>mx)
            {
                mx=tmp;
                mxid=i;
            }
        }
        g=mx;
        vis[mxid]=1;
        ans.emplace_back(a[mxid]);
        cnt++;
        if(cnt==n) break;
    }
    rep(i,0,ans.size()-1) cout<<ans[i]<<" ";
    rep(i,1,n) 
    {
        if(!vis[i]) cout<<a[i]<<" ";
    }
    cout<<endl;
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