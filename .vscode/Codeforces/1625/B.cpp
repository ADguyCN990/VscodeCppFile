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
int pos[MAXN];
void solve()
{
    n = read();
    for (int i = 1; i <= n; i ++) a[i] = read();
    memset(pos, 0, sizeof pos);
    ll ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (pos[a[i]])
        {
            ans = max(ans, pos[a[i]] + n - i);
        }
        pos[a[i]] = i;
    }
    if(!ans) puts("-1");
    else printf("%lld\n", ans);
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