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
ll n;
ll a[MAXN];
int vis[MAXN];
void solve()
{
    n = read();
    for (int i = 1; i <= n; i ++)
        a[i] = read(),vis[i] = 0;
    sort(a + 1, a + 1 + n, greater <int>());
    for (int j = n; j > 0; j --)
    {
        bool flag = false;
        for(int i = 1; i <= n; i ++)
        {
            if (vis[i]) continue;
            for (int k = 0; k <= 31; k ++)
            {
                int num = 1 << k;
                if (a[i] / num == j)
                {
                    flag = true;
                    vis[i] = 1;
                    break;
                }
            }
            if (flag == true)
                break;
        }
        if (!flag)
        {
            puts("NO");
            return;
        }
    }
    puts("YES");
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