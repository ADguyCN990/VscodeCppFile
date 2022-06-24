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
vector <int> mp[MAXN];
vector <int> mx;
void solve()
{
    int m,n;
    m=read(),n=read();
    rep(i,0,m) mp[i].clear();
    mx.clear();
    int p1=0,p2=0;
    rep(i,1,m)
    {
        mp[i].pb(0);
        rep(j,1,n)
        {
            int tmp=read();
            mp[i].pb(tmp);
        }
    }
    
    rep(i,1,n)
    {
        int tmp=0;
        rep(j,1,m)
        {
            tmp=max(tmp,mp[j][i]);
        }
        mx.pb(tmp);
    }
    sort(mx.begin(),mx.end());   
    p2=mx[0];
    
    for(int i=1;i<=m;i++) sort(mp[i].begin(),mp[i].end(),greater<int>());
    rep(i,1,m)
    {
        p1=max(p1,mp[i][1]);
    }
    
    printf("%d\n",min(p1,p2));
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