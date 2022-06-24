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
int a[MAXN];
int dp1[MAXN], dp2[MAXN];
void solve()
{
    n = read();
    dp2[n + 1] = 0;
    for (int i = 1; i <= n; i ++) a[i] = read();
    for (int i = 1; i <= n; i ++)
    {
        if (a[i] >= a[i - 1])
            dp1[i] = dp1[i - 1] + 1;
        else
            dp1[i] = 1;
        //printf("%d ",dp1[i]);
    }
    //puts("");
    for (int i = n; i >= 1; i --)
    {
        if (a[i] >= a[i + 1])
            dp2[i] = dp2[i + 1] + 1;
        else
            dp2[i] = 1;
    }
    // for (int i = 1; i <= n; i ++) printf("%d ", dp2[i]);
    // puts("");
    int ans = INF;
    for (int i = n; i >= 1; i --)
    {
        int down = dp2[i];
        int up = dp1[i];
        if (down != n - i + 1) continue;
        int len = dp1[i] + dp2[i] - 1;
        ans = min(ans, n - len);
    }
    printf("%d\n", ans);
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