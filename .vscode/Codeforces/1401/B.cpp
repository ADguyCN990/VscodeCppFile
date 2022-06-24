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
bool a, b;
void solve()
{
    ll x, xx, y, yy, z, zz;
    x = read(), y = read(), z = read(), xx = read(), yy = read(), zz = read();
    //x 0 y 1 z 2
    // if (a && !b) return;
    // if (a && b)
    // {
    //     printf("%lld %lld %lld %lld %lld %lld",x, y, z, xx, yy, zz);
    //     return;
    // }
    ll ans = 0;
    ans += min(z, yy) * 2;
    int mn = min(z, yy);
    z -= mn, yy -= mn;
    y = max(0ll, y - xx - yy), zz = max(0ll, zz - x - z);
    ans -= min(zz, y) * 2;
    printf("%lld\n", ans);
}

int main()
{
    int T;
    T=read();
    // a = false;
    // if (T == 7941) a = true;
    for (int i = 1; i <= T; i ++)
    {
        // b = false;
        // if (i == 224) b = true;
        solve();
    }
    return 0;
}