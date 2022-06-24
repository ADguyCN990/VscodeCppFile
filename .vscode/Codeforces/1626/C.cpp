#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
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
ll k[MAXN], h[MAXN];
void solve()
{
    n = read();
    rep (i, 1, n) k[i] = read(); //怪物出现的时间
    rep (i, 1, n) h[i] = read(); //怪物的血量
    ll ans = 0, now, last; //ans表示总代价，now表示当前提前施法所在的位置
    per (i, n, 1)
    {
        // if (i == n)
        // {
        //     now = k[i] - h[i] + 1;
        //     ans += h[i] * (h[i] + 1) / 2;
        //     last = k[i];
        //     continue;
        // }
        if (now > k[i] || i == n) //有充足的时间杀死下一个怪物
        {
            now = k[i] - h[i] + 1;
            ans += h[i] * (h[i] + 1) / 2;
            last = k[i];
        }
        else //为了杀死下下一个怪物，在碰到下个怪物前就要开始蓄力
        {
            if (k[i] - now + 1 >= h[i]) //顺便能够把当前怪物带走
            {
                continue;
            }
            ll x = last - now + 1; //之前计算出来的需要蓄力的基础时间
            ll y = h[i] - (k[i] - now + 1); //为了杀死当前怪物需要蓄力的时间
            ans += y * (y + 1) / 2 + x * y;
            now = now - y;
        }
    }
    printf("%lld\n", ans);
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