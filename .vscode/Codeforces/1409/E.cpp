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
int n, k;
int a[MAXN];
map <int, int> mp;
int l[MAXN], r[MAXN];
ll sum[MAXN];
void solve()
{
    mp.clear();
    n = read(), k = read();
    for (int i = 1; i <= n; i ++) a[i] = read(), mp[a[i]] ++;
    for (int i = 1; i <= n; i ++) int bullshit = read();
    sort(a + 1, a + 1 + n);
    n = unique(a + 1, a + 1 + n) - a - 1;
    for (int i = 1; i <= n; i ++)
    {
        sum[i] = sum[i - 1] + mp[a[i]];
        r[i] = 0;
        l[i] = i;
    }
    for (int i = 1; i <= n; i ++)
    {
        int tmp = upper_bound(a + i, a + 1 + n, a[i] + k) - a - 1;
        r[i] = tmp;
        l[tmp] = min(l[tmp], i);
    }
    ll ans = 0;
    ll mx = 0;
    for (int i = 1; i <= n; i ++)
    {
        ll sum1 = sum[i - 1] - sum[max(0,l[i - 1] - 1)];
        mx = max(mx,sum1);
        ll sum2 = sum[r[i]] - sum[i - 1];
        ans = max(ans,mx + sum2);
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