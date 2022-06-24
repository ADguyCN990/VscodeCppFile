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
ll n, x, y;
ll a[MAXN];
void solve()
{
    n = read(), x = read(), y = read();
    ll sum = 0;
    for (int i = 1; i <= n; i ++) a[i] = read(), sum += a[i];
    if (x + sum == y)
    {
        puts("Alice");
        return;
    }
    if (x + 3 + sum == y)
    {
        puts("Bob");
        return;
    }
    int now;
    if (x & 1) now = 1;
    else now = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (now && a[i] & 1 || !now && a[i] % 2 == 0) now = 0;
        else now = 1;
    }
    if (now == y % 2) puts("Alice");
    else puts("Bob");
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