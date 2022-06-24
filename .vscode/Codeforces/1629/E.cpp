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
int n;
ll g[MAXN][MAXN];
int cnt[MAXN][MAXN];
void solve()
{
    n = read();
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            g[i][j] = read();
    ll ans = 0;
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            if(!cnt[i - 1][j] && !cnt[i + 1][j] && !cnt[i][j - 1] && !cnt[i][j + 1])
            {
                ans ^= g[i][j];
                cnt[i - 1][j] ++, cnt[i + 1][j] ++, cnt[i][j - 1] ++, cnt[i][j + 1] ++;
            }
        }
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