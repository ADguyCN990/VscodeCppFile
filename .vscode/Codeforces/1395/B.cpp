#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
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
int n, m;
int x, y;
int vis[MAXN][MAXN];

void output(int x, int y)
{
    printf("%d %d\n", x, y);
}

int work(int now, int last)
{
    if (last == 1)
    {
        for (int i = 1; i <= m; i ++)
        {
            if (vis[now][i]) continue;
            output(now, i);
            vis[now][i] = 1;
        }
        return m;
    }
    else
    {
        for (int i = m; i >= 1; i --)
        {
            if (vis[now][i]) continue;
            output(now, i);
            vis[now][i] = 1;
        }
        return 1;
    }
}

void solve()
{
    n = read(), m = read();
    x = read(), y = read();
    vis[x][y] = 1;
    output(x, y);
    int last = 1;
    for (int now = x; now >= 1; now --)
    {
        last = work(now, last);
    }
    for (int now = x + 1; now <= n; now ++)
    {
        last = work(now, last);
    }
}

int main()
{
    solve();
    return 0;
}