#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define debug(x) cout<<x<<endl
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
char s[MAXN];
void solve()
{
    //Raze 先手 奇数位置 ；Breach 后手 偶数位置
    ll n,tmp;
    n=read();
    ll cnt1=0,cnt2=0;
    cin>>s+1;
    rep(i,1,n)
    {
        tmp=s[i]-'0';
        if((i&1)&&(tmp&1)) cnt1++;
        else if(!(i&1)&&!(tmp&1)) cnt2++;
    }
    int ans;
    if((n&1)&&cnt1>0)
    {
        ans=1;
    }
    else if((n&1)&&cnt1==0)
    {
        ans=2;
    }
    else if(!(n&1)&&cnt2>0)
    {
        ans=2;
    }
    else if(!(n&1)&&cnt2==0)
    {
        ans=1;
    }
    debug(ans);
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