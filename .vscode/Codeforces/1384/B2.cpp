#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
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
ll n, k, l;
ll a[MAXN];
vector <int> safe;
void solve()
{
    n = read(), k = read(), l = read();
    safe.clear();
    safe.pb(0);
    for (int i = 1; i <= n; i ++) a[i] = read();
    for (int i = 1; i <= n; i ++)
    {
        int h = a[i] + k;
        if (h <= l) safe.pb(i);
    }
    safe.pb(n + 1);
    for (int i = 1; i < safe.size(); i ++)
    {
        bool low = true;
        ll extra = k;
        for (int j = safe[i - 1] + 1; j < safe[i]; j ++)
        {
            if (low) 
                extra --;
            else
                extra ++;
            if (a[j] + extra > l) //目前还过不了
            {
                if (!low) //还是涨潮的状态
                {
                    puts("No");
                    return;
                }
                extra -= a[j] + extra - l;
            }
            if (extra < 0)
            {
                puts("No");
                return;
            }
            if (extra == 0) //变成涨潮
            {
                low = false;
            }
        }
    }
    puts("Yes");
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