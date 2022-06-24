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
ll a[MAXN];
ll n;

bool check()
{
    if (a[1] > 1) return false;
    if (a[1] == 0) return true;
    for (int i = 2; i <= n; i ++)
        if (a[i] != a[i - 1] * 2)
            return true;
    return false;
}

void solve()
{
    n = read();
    for (int i = 1; i <= n; i ++) a[i] = read();
    bool flag = check();
    if (!flag)
    {
        puts("-1");
        return;
    }
    if (a[1] == 0) //特判mod等于1的情况
    {
        for (int i = 2; i <= n; i ++)
        {
            if (a[i])
            {
                puts("-1");
                return;
            }
        }
        puts("1"); //mod就是等于1
        return;
    }
    //mod = a[pre] * 2 - a[now]
    int pos = 2, mod = 0;
    while (pos <= n && a[pos - 1] * 2 == a[pos]) pos ++;
    mod = a[pos - 1] * 2 - a[pos];
    for (int i = pos; i <= n; i ++)
    {
        if (a[i] != a[i - 1] * 2 % mod) //检查出来不正确
        {
            puts("-1");
            return;
        }
    }
    printf("%d\n", mod);
}

int main()
{
    int T;
    T = read();
    while (T --)
    {
        solve();
    }
    return 0;
}