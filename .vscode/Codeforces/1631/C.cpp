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
ll n, k;
void solve()
{
    n = read(), k = read();
    if (k == n - 1)
    {
        if (n <= 4)
        {
            puts("-1");
            puts("");
            return;
        }
        printf("%lld %lld\n", n - 1, n - 2);
        printf("%lld 1\n", n - 3);
        printf("0 %lld\n", 2);
        for (ll i = 3; i < n / 2; i ++) printf("%lld %lld\n", i, n - i - 1);
        puts("");
        return;
    }
    if (k == 0)
    {
        for (ll i = 0; i < n / 2; i ++)
        {
            printf("%lld %lld\n", i, n - i - 1);
        }
        return;
    }
    printf("0 %lld\n", n - k - 1);
    printf("%lld %lld\n", n - 1, k);
    for (ll i = 1; i < n / 2; i ++)
    {
        if (i == k || i == n - k - 1) continue;
        printf("%lld %lld\n", i, n - i - 1);
    }
    puts("");
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