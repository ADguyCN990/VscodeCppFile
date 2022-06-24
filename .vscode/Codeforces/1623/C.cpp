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
int n;
int a[MAXN];
int b[MAXN];
bool check(int a[],int h)
{
    for(int i = 1; i <= n; i ++) b[i] = a[i];
    for (int i = n; i >= 3; i --)
    {
        if (b[i] < h)
            return false;
        int dx = min(a[i], b[i] - h) / 3;
        b[i - 1] += dx;
        b[i - 2] += 2 * dx;
    }
    if (b[1] < h || b[2] < h)
        return false;
    return true;
}

void solve()
{
    n = read();
    int mn = INF, mx = -1;
    for (int i = 1; i <= n; i++)
        a[i] = read(), mn = min(mn, a[i]), mx = max(mx, a[i]);
    int l = mn;
    int r = mx;
    int ans;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (check(a, mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
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