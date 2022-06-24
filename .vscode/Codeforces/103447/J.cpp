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
int n, m;
ll a[MAXN][MAXN];
void solve()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            a[i][j] = read();
    int cnt = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
        {
            ll mn = INF;
            for (int k = 1; k <= n; k ++)
                mn = min(mn, a[k][j]);
            for (int k = 1; k <= m; k ++)
                mn = min(mn, a[i][k]);
            if (mn == a[i][j])
            {
                cnt ++;
            }
        }
    printf("%d\n", cnt);
}

int main()
{
    solve();
    return 0;
}