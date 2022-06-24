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
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}
ll n;
void solve()
{
    n = read();
    if (n % 2 == 0)
    {
        printf("%lld %lld\n", n / 2, n / 2);
        return;
    }
    int m = round(sqrt(n));
    for (int i = 3; i * i <= n; i ++)
    {
        if (n % i == 0)
        {
            printf("%lld %lld\n", n / i, n - n / i);
            return;
        }
    }
    printf("1 %lld\n", n - 1);
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