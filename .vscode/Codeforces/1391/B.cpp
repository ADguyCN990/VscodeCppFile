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
char g[MAXN][MAXN];
void solve()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i ++)
    {
        scanf("%s", g[i] + 1);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (g[i][1] == 'L') cnt ++;
        if (g[i][m] == 'R') cnt ++;
    }
    for (int i = 1; i <= m; i ++)
    {
        if (g[1][i] == 'U') cnt ++;
        if (g[n][i] == 'D') cnt ++;
    }
    printf("%d\n", cnt);
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