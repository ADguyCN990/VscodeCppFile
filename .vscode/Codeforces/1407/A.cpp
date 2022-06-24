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
void solve()
{
    n=read();
    rep(i,1,n) a[i]=read();
    int cnt=0;
    vector <int> v;
    for(int i=1;i<=n;i+=2)
    {
        if(a[i]==1&&a[i+1]==1) {v.emplace_back(1);v.emplace_back(1);cnt+=2;}
        else if(a[i]==0&&a[i+1]==0) {v.emplace_back(0);v.emplace_back(0);cnt+=2;}
        else {v.emplace_back(0);cnt++;}
    }
    cout<<cnt<<endl;
    rep(i,0,cnt-1) cout<<v[i]<<" ";
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