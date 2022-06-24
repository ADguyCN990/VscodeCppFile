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
int a[MAXN], have1[MAXN], have2[MAXN];

int highbit(int n)
{
    for (int i = 31; i >= 0; i --)
    {
        int u = n >> i & 1;
        if (u) return i;
    }
}

void solve()
{
    n = read();
    for (int i = 0; i < n; i ++) a[i] = read();
    sort(a, a + n);
    int k = highbit(n);
    for (int i = 0; i <= k; i ++)
    {
        int have = 0;
        while (have < (1 << i) && a[have] < a[1 << i]) have ++;
        have1[i] = have;
    }
    reverse(a, a + n);
    for (int i = 0; i <= k; i ++)
    {
        int have = 0;
        while (have < (1 << i) && a[have] > a[1 << i]) have ++;
        have2[i] = have;
    }
    int ans = INF;
    for (int i = 0; i <= k; i ++)
    {
        for (int j = 0; j <= k; j ++)
        {
            int mid = max(1, n - have1[i] - have2[j]);
            int kk = highbit(mid);
            if ((1 << kk) != mid) mid = 1 << (kk + 1);
            ans = min(ans, (1 << i) + (1 << j) + mid - n);
        }
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