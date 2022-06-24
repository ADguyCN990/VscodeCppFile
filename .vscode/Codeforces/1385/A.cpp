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
void solve()
{
    // ab ac bc
    ll x, y, z;
    x = read(), y = read(), z = read();
    if (x != y && x != z && y != z)
    {
        puts("NO");
        return;
    }
    if (x == y)
    {
        if (x < z)
        {
            puts("NO");
            return;
        }
        puts("YES");
        printf("%lld %lld %lld\n", x, z, z);
    }
    else if (x == z)
    {
        if (x < y)
        {
            puts("NO");
            return;
        }
        puts("YES");
        printf("%lld %lld %lld\n", y, x, y);
    }
    else if (y == z)
    {
        if (y < x)
        {
            puts("NO");
            return;
        }
        puts("YES");
        printf("%lld %lld %lld\n", x, x, z);
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