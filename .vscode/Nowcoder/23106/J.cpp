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
int n, m, len;
int quiet[MAXN];
int noise[MAXN];
void solve()
{
    n = read(), m = read(), len = read();
    for (int i = 1; i <= n; i ++) quiet[i] = read();
    for (int i = 1; i <= m; i ++) noise[i] = read();
    sort(quiet + 1, quiet + 1 + n, greater<int>());
    sort(noise + 1, noise + 1 + m, greater<int>());
    if (n < (len + 1) / 2)
    {
        puts("-1");
        return;
    }
    quiet[n + 1] = 0, noise[m + 1] = 0;
    ll ans = 0;
    for (int i = 1; i <= (len + 1) / 2; i ++) ans += quiet[i];
    int p1 = (len + 1) / 2 + 1;
    int p2 = 1;
    int left = len / 2;
    while (left)
    {
        if (quiet[p1] > noise[p2]) ans += quiet[p1 ++];
        else ans += noise[p2 ++];
        left --;
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