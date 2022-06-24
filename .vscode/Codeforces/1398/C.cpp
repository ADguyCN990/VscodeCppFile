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
int n;
char s[MAXN];
int a[MAXN], sum[MAXN];
map <ll, ll> mp;
void solve()
{
    n = read();
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i ++) a[i] = s[i] - '0';
    for (int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + a[i];
    mp.clear();
    for (int i = 0; i <= n; i ++) mp[sum[i] - i] ++;
    ll ans = 0;
    for (auto it : mp)
    {
        ll x = it.second;
        ans += x * (x - 1) / 2;
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