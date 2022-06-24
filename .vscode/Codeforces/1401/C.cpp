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
ll gcd(ll a,ll b)
{
    if(a<b) swap(a,b);
    ll tmp;
    while(b)
    {
       tmp=b;
       b=a%b;
       a=tmp; 
    }
    return a;
}
int n;
int a[MAXN];
int b[MAXN];
int mn;
void solve()
{
    n = read();
    mn = INF;
    for (int i = 1; i <= n; i ++) a[i] = read(), mn = min(mn, a[i]);
    for (int i = 1; i <= n; i ++) b[i] = a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i ++)
    {
        if (a[i] != b[i] && a[i] % mn != 0)
        {
            puts("NO");
            return;
        }
    }
    puts("YES");
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