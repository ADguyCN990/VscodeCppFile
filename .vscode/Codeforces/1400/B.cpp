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
ll n, m;
ll cnta, cntb;
ll a, b;
void solve()
{
    n = read(), m = read();
    cnta = read(), cntb = read();
    a = read(), b = read();
    int a1 = 0, b1 = 0, a2 = 0, b2 = 0;
    if (a > b) swap(a, b), swap(cnta, cntb);
    if (n < m) swap(n, m);
    int ans = -1;
    for (int i = 0; i <= cnta; i ++)
    {
        if (i * a > n) break;
        a1 = i;
        b1 = min(cntb, (n - a * a1) / b);
        a2 = min(cnta - a1, m / a);
        b2 = min((m - a * a2) / b, cntb - b1);
        ans = max(a1 + b1 + a2 + b2, ans);
        //printf("a1: %d b1: %d a2: %d b2 : %d\n", a1, b1, a2, b2);
    }
    printf("%d\n", ans);
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