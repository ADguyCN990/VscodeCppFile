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
int cnt[40][2];
ll n, m;
void solve()
{
    n = read(), m = read();
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i ++) 
    {
        int tmp = read();
        for (int j = m - 1; j >= 0; j --)
        {
            int now = tmp >> j & 1;
            cnt[j][now] ++;
        }
    }
    ll ans = 0;
    for (int i = m - 1; i >= 0; i --)
    {
        if(cnt[i][0] >= cnt[i][1])
            ans += 0;
        else
            ans += (1 << i);
    }
    printf("%lld\n", ans);
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