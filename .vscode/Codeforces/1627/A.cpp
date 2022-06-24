#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 55
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
char s[MAXN][MAXN];
int n, m, x, y;
void solve()
{
    n = read(), m = read(), x = read(), y = read();
    for (int i = 1; i <= n; i ++)
    {
        scanf("%s", s[i] + 1);
    }
    bool f = false;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n ; i ++)
        for (int j = 1; j <= m; j ++)
            if (s[i][j] == 'B')
                f = true;
    if (!f)
    {
        puts("-1");
        return;
    }
    if (s[x][y] == 'B') 
    {
        puts("0");
        return;
    }
    for (int i = 1; i <= m; i ++)
        if (s[x][i] == 'B') cnt1 ++;
    for (int i = 1; i <= n; i ++)
        if (s[i][y] == 'B') cnt2 ++;
    if (cnt1 == 0 && cnt2 == 0)
    {
        puts("2");
        return;
    }
    puts("1");
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