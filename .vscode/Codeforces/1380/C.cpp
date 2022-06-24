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
ll n, x;
ll a[MAXN];

int find(ll x) //最后一个大于等于x的位置
{
    int l = 1, r = n;
    int ans = 0;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (a[mid] >= x)
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return ans;
}

void solve()
{
    n = read(), x = read();
    for (int i = 1; i <= n; i ++) a[i] = read();
    sort(a + 1, a + 1 + n, greater<ll>());
    int pos = find(x);
    int cnt = 0;
    int len = 1;
    for (int i = pos + 1; i <= n; i ++)
    {
        if (a[i] * len >= x)
        {
            len = 1;
            cnt ++;
        }
        else
            len ++;
    }
    printf("%d\n", cnt + pos);
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