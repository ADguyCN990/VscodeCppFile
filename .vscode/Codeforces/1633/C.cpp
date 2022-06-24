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
ll a, b, x, y;
ll k, ap, bp;
void solve()
{
    a = read(), b = read(), x = read(), y = read();
    k = read(), bp = read(), ap = read();
    for (int i = 0; i <= k; i ++)
    {
        ll cnta = i; // 用cnta个金币来升级生命值
        ll cntb = k - i; //用cntb个金币来升级攻击力
        ll hp = a + cnta * ap; //当前生命值
        ll dps = b + cntb * bp; //当前攻击力
        ll myturn = (x + dps - 1) / dps; //把敌人打死的回合数
        ll enemyturn = (hp + y - 1) / y; //敌人打死自己的回合数
        if (myturn <= enemyturn)
        {
            //printf("myturn : %lld enemyturn : %lld\n", myturn, enemyturn);
            puts("YES");
            return;
        }
    }
    puts("NO");
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