#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f3f3f3f3f
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
ll n, k, l1, r1, l2, r2;
void solve()
{
    n = read(), k = read();
    l1 = read(), r1 = read();
    l2 = read(), r2 = read();
    if (r1 >= l2 && r2 >= l1) //有相交部分
    {
        int len = min(r1, r2) - max(l1, l2);
        if (k - len * n <= 0)
        {
            puts("0");
            return;
        }
        ll extra = max(r1, r2) - min(r1, r2) + max(l1, l2) - min(l1, l2);
        if (extra * n + len * n >= k) //还不用往外扩张
        {
            printf("%lld\n", k - len * n);
            return;
        }
        // 必须往外扩张
        ll ans1 = extra * n;
        ll ans2 = 2 * (k - len * n - extra * n);
        printf("%lld\n", ans1 + ans2);
    }
    else //初始线段没有相交的部分
    {
        ll len = max(r1, r2) - min(l1, l2);
        ll opt = max(l1, l2) - min(r1, r2); //需要多少次操作才能相交
        ll ans = INF;
        for (int i = 1; i <= n; i ++) //先使i段线段相交，有有限次机会用一次操作换取一单位的长度，若不够长就用两次操作换取一单位的长度增加
        {
            ll tmp = i * opt;
            ll now = len * i;
            if (now >= k)
                ans = min(ans, tmp + k);
            else
                ans = min(ans, tmp + now + (k - now) * 2);
        }
        printf("%lld\n", ans);
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