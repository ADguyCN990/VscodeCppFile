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
int n, m;
int a[MAXN];
void solve()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i ++) a[i] = read();
    int less = 0, great = 0; 
    for (int i = 1; i <= n; i ++)
    {
        if (a[i] < m) less ++;
        else great ++;
    }
    if (great <= less)
    {
        puts("-1");
        return;
    }
    int now_less = 0, now_great = 0;
    int ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (a[i] >= m)
        {
            now_great ++;
            great --;
            if (now_great > now_less && great > less)
            {
                now_less = 0, now_great = 0;
                ans ++;
            }
            else if (now_great > now_less && great <= less)
            {
                printf("%d\n", ans + 1);
                return;
            }
            else
                continue;
        }
        else
        {
            now_less ++;
            less --;
        }
    }
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