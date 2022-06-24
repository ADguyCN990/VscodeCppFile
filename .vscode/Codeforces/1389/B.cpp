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
ll n, k, z;
ll a[MAXN];
ll sum[MAXN];
ll mx[MAXN]; //从第i个点开始反复横跳
void solve()
{
    n = read(), k = read(), z = read();
    for (int i = 1; i <= n; i ++) a[i] = read();
    for (int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + a[i];
    for (int i = 2; i <= n; i ++) mx[i] = max(mx[i - 1], a[i] + a[i - 1]); //必定是反复横跳
    ll ans = sum[k + 1];
    for (int i = 1; i <= min(k / 2, z); i ++) //枚举反复横跳的次数
    {
        int pos = k - 2 * i + 1 + 1;
        ans = max(ans, mx[pos] * i + sum[pos - 1]);
    }
    printf("%lld\n", ans);
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