#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define mod 1000000007
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
int n, m, k; //积木数目，颜色种类，染色次数
char s[MAXN];
int color[MAXN];

void work()
{
    for (int l = 1, r = 1; l <= n; l = r + 1, r = l)
    {
	    while (r < n && (color[l]==color[r+1]) ) r ++;
        sort(s + l, s + 1 + r, greater<char>());
    }
    ll ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        int u = s[i] - '0';
        ans = (ans * 10 + u) % mod;
    }
    printf("%lld\n", ans);
}

void solve()
{
    n = read(), m = read(), k = read();
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i ++) color[i] = read();
    for (int tim = 0; tim <= k; tim ++)
    {
        if (tim != 0)
        {
            int u, v;//颜色为u的染成v
            u = read(), v = read();
            for (int i = 1; i <= n; i ++) 
                if (color[i] == u)
                    color[i] = v;
        }
        work();

    }
}

int main()
{
    solve();
    return 0;
}