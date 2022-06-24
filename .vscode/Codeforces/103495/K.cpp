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
ll ans[MAXN];
int idx;
void pre()
{
    ans[0] = 1;
    ans[1] = 2;
    ans[2] = 3;
    idx = 3;
    for (ll i = 2; ; i ++)
    {
        ans[idx] = ans[idx - 1] + i * (1 << (i - 1));
        //printf("%lld\n", ans[idx]);
        if (ans[idx] > 1e9) return;
        idx ++;
    }
}

void solve()
{
    int n;
    n = read();
    int l = 0, r = idx;
    int res;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (ans[mid] <= n)
        {
            res = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    printf("%d\n", res);
}

int main()
{
    pre();
    int T;
    T=read();
    while(T--)
    {
        solve();
    }

    return 0;
}