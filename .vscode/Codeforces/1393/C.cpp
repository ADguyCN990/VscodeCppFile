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
int cnt[MAXN];
int mx, mxcnt;
void solve()
{
    n = read();
    for (int i = 1; i <= n; i ++) cnt[i] = 0;
    mx = -1, mxcnt = 0;
    for (int i = 1; i <= n; i ++)
    {
        int tmp = read();
        cnt[tmp] ++;
    }
    for (int i = 1; i <= n; i ++)
    {
        if (cnt[i] > mx)
        {
            mx = cnt[i], mxcnt = 1;
        }
        else if (cnt[i] == mx)
            mxcnt ++;
    }
    int ans = mxcnt - 1 + (n - mxcnt * mx) / (mx - 1);
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