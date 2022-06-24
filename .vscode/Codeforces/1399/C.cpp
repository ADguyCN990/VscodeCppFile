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
int n;
int a[MAXN];
int vis[MAXN];

int check(int x)
{
    int cnt = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (vis[i]) continue;
        for (int j = 1; j <= n; j ++)
        {
            if (vis[j]) continue;
            if (a[i] + a[j] == x && i != j)
            {
                cnt ++;
                vis[i] = 1, vis[j] = 1;
                break;
            }
        }
    }
    return cnt;
}

void solve()
{
    n = read();
    for (int i = 1; i <= n; i ++) a[i] = read();
    int ans = 0, mx = 0;
    for (int i = 1; i <= n * 2; i ++)
    {
        memset(vis, 0, sizeof vis);
        int cnt = check(i);
        if (cnt > mx)
        {
            mx = cnt;
            ans = i;
        }
    }
    printf("%d\n", mx);
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