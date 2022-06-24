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
ll n, m, d;
ll a[MAXN], an; //破防的
ll b[MAXN], bn; //不破防的
ll suma[MAXN], sumb[MAXN];
void solve()
{
    n = read(), d = read(), m = read();
    for (int i = 1; i <= n; i ++) 
    {
        ll tmp = read();
        if (tmp > m)
            a[++ an] = tmp;
        else
            b[++ bn] = tmp;
    }
    sort(a + 1, a + 1 + an, greater<ll>());
    sort(b + 1, b + 1 + bn);
    for (int i = 1; i <= an; i ++) suma[i] = suma[i - 1] + a[i];
    for (int i = 1; i <= bn; i ++) sumb[i] = sumb[i - 1] + b[i];

    // printf("a: ");
    // for (int i = 1; i <= an; i ++) printf("%lld ", a[i]);
    // puts("");
    // printf("b: ");
    // for (int i = 1; i <= bn; i ++) printf("%lld ", b[i]);
    // puts("");

    ll ans = sumb[bn]; //起码能够保证的答案
    for (int i = 1; i <= an; i ++) //选择i个破防话时的情况
    {   
        if ((i - 1) * (d + 1) >= n) break; //破防一天，禁言d天，一组需要d+1天
        ll allneed = (i - 1) * d; //需要来填坑的数目
        ll ahave = (an - i); //a中能填坑的数目
        ll bneed = max(allneed - ahave, 0ll); //b中前面bneed个数被拿来填坑，[bneed+1,bn]依然有效
        ll tmp = suma[i] + (sumb[bn] - sumb[bneed]);
        //printf("choose: %d allneed: %lld ahave: %lld bneed: %lld tmp_ans: %lld\n", i, allneed, ahave, bneed, tmp);
        ans = max(ans, tmp);
    }
    printf("%lld\n", ans);
}

int main()
{
    solve();
    return 0;
}