#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
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
int d[MAXN];
int pre[MAXN];
void solve()
{
    n = read();
    int mx = 0;
    for (int i = 1; i <= n; i ++)
    {
        int x, y, xx, yy;
        x = read(), y = read(), xx = read(), yy = read();
        mx = max({mx, x, xx});
        x = x + 1;
        d[x] ++, d[xx + 1] --;      
    }
    int sum = 0, cnt = 0;
    for (int i = 1; i <= mx; i ++)
    {
        sum += d[i];
        if (sum != 0) cnt ++;
    }
    printf("%d\n", cnt);
}

int main()
{
    solve();
    return 0;
}