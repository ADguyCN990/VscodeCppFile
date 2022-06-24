#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 10005
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
int a[MAXN];
void solve()
{
    n = read();
    for (int i = 1; i <= n; i ++) a[i] = read();
    ll ans = 0;
    for (int i = 1; i <= n - 1; i ++)
    {
        ll mn, mx;
        mn = min(a[i], a[i + 1]);
        mx = max(a[i], a[i + 1]);
        ans += mn;
        for (int j = i + 2; j <= n; j ++)
        {
            if (a[j] > mx)
            {
                mn = mx, mx = a[j];
            }
            else if (a[j] > mn && a[j] < mx)
            {
                mn = a[j];
            }
            ans += mn;
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    solve();
    return 0;
}