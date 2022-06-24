#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
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
ll sum[MAXN];
int n;
int findless(int x) //最后一位 a[x] + a[pos] < 1000 的位置
{
    int val = a[x];
    int l = x, r = n;
    int ans = -1;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (a[mid] + val < 1000)
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return ans;
}

int findgreat(int x) //第一位 a[x] + a[pos] > 1000 的位置
{
    int val = a[x];
    int l = x, r = n;
    int ans = -1;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (a[mid] + val > 1000)
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return ans;
}

void solve()
{
    n = read();
    for (int i = 1; i <= n; i ++)
    {
        a[i] = read();
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + a[i];
    // for (int i = 1; i <= n; i ++) printf("%lld ", a[i]);
    // puts("");
    ll ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        int great = findgreat(i);
        int less =  findless(i);
        int qian = 0;
        //printf("less: %d, great: %d\n", less, great);
        int cntless = 0;
        int cntgreat = 0;
        if (less != -1) cntless = less - i + 1;
        if (great != -1) cntgreat = n - great + 1;
        //printf("cntless: %d, cntgreat: %d\n", cntless, cntgreat);
        ans -= cntless * a[i];
        ans += cntgreat * a[i];
        if (less != -1) ans -= (sum[less] - sum[i - 1]);
        if (great != -1) ans += (sum[n] - sum[great - 1]);
        qian += cntless, qian -= cntgreat;
        ans += 1000 * qian;
    }
    printf("%lld\n", ans);
}

int main()
{
    solve();
    return 0;
}