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
int n;
int a[MAXN];
int cnt[MAXN];
ll ans[MAXN];
int stk[MAXN],tt;
void solve()
{
    n=read();
    rep(i,0,n) cnt[i]=0,ans[i]=-1;
    rep(i,1,n) a[i]=read(),cnt[a[i]]++;
    sort(a+1,a+1+n);
    tt=0;
    ll m=0;//维护单调栈的总成本
    rep(i,0,n)
    {
        ll op=m;//本轮需要的操作次数
        if(cnt[i]>0)
        {
            op+=cnt[i];
        }
        if(i&&cnt[i-1]==0)
        {
            if(tt==0)//如果需要单调栈来维护且单调栈为空，那么为非法情况
            {
                break;
            }
            int now=stk[tt];tt--;
            op+=i-1-now,m+=i-1-now;
        }
        ans[i]=op;
        rep(j,1,cnt[i]-1) stk[++tt]=i;
    }
    rep(i,0,n)
    {    
        cout<<ans[i]<<" ";
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