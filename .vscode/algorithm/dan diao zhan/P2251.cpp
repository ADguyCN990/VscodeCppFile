#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
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
int a[MAXN];
int q[MAXN];
int hh = 1, tt = 0;
int n, k;
void solve()
{
    n = read(), k = read();
    for (int i = 1; i <= n; i ++) a[i] = read();
    for (int i = 1; i <= n; i ++)
    {
        while (hh <= tt && a[i] <= a[q[tt]]) tt --;
        q[++ tt] = i;
        if (i - k + 1 > q[hh]) hh ++;
        if (i >= k) printf("%d\n", a[q[hh]]);
    }
}

int main()
{
    solve();
    return 0;
}