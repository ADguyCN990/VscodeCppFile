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
int cnt[35];

void work(int x)
{
    for (int i = 31; i >= 0; i --)
    {
        int u = x >> i & 1;
        if (u) cnt[i] ++;
    }
}

void solve()
{
    n = read();
    for (int i = 1; i <= n; i ++) a[i] = read();
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i ++)
    {
        work(a[i]);
    }
    for (int i = 31; i >= 0; i --)
    {
        if (cnt[i] % 4 == 0 || cnt[i] % 4 == 2) continue;
        if (cnt[i] % 4 == 3 && n % 2 == 1) //最高位有奇数个并且由于是先手必须最后一手把这个最高位拿了然后归0
        {
            puts("LOSE");
        }
        else if (cnt[i] % 4 == 1 || cnt[i] % 4 == 3 && n % 2 == 0) //直接拿最高位获胜或者把最后余出来的最高位塞给对面让它变成0
            puts("WIN");
        return;
    }
    puts("DRAW");

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