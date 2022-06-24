#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 50
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
int n, k;
char mp[MAXN][MAXN];
void solve()
{
    n = read(), k = read();
    if (k > (n + 1) / 2)
    {
        puts("-1");
        return;
    }
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            mp[i][j] = '.';
    for (int i = 1, j = 1; i <= k; i ++, j += 2)
    {
        mp[j][j] = 'R';
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            printf("%c", mp[i][j]);
        }
        puts("");
    }
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