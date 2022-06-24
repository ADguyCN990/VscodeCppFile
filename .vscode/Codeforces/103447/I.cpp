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
int bit[40];
int sum;
void work(ll x)
{
    int pos = 0;
    for (int i = 0; i <= 35; i ++)
    {
        int u = x >> i & 1;
        pos ++;
        if (u) bit[pos] ++;
    }
}

void solve()
{
    n = read();
    for (int i = 1; i <= n; i ++) a[i] = read();
    memset(bit, 0, sizeof bit);
    for (int i = 1; i <= n; i ++)
        work(a[i]);
    sum = 0;
    for (int i = 1; i <= 39; i ++) sum += bit[i];
    int ans = 0;
    while (sum)
    {
        for (int i = 1; i <= 39; i ++)
        {
            if (bit[i])
            {
                bit[i] --;
                sum --;
                continue;
            }
            else
            {
                bool flag = false;
                for (int j = i; j <= 39; j ++)
                {
                    if (bit[j]) 
                    {
                        flag = true;
                        break;
                    }
                }
                if (!flag) break;
                for (int j = i; ; j ++)
                {
                    if (!bit[j])
                    {
                        bit[j] ++;
                        sum ++;
                    }
                    else
                    {
                        bit[j] --;
                        sum --;
                        break;
                    }
                }
            }
        }
        ans ++;
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