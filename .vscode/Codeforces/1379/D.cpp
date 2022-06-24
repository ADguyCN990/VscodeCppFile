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
int n, m, h, k;
struct node
{
    int id;
    ll val;
    friend bool operator < (node a, node b) 
    {
        if (a.val == b.val)
            return a.id < b.id;
        return a.val < b.val;
    }
}a[MAXN];
void solve()
{
    n = read(), h = read(), m = read(), k = read();
    int mod = m / 2;
    int cnt = 0;
    for (int i = 1; i <= n; i ++) 
    {
        int g = read(), tmp = read();
        a[++ cnt].id = i, a[cnt].val = tmp % mod;
        a[++ cnt].id = i, a[cnt].val = tmp % mod + mod; //这是为了组成一个环
    }
    sort(a + 1, a + 1 + cnt);
    pii ans = {INF, -1}; //first表示调整数量，second表示发车时间
    int j = 1;
    for (int i = 1; i <= 2 * n; i ++) //发车时间为t,上车时间为t - k,[t - k + 1, t - 1]这段时间的车要停掉
    {
        while (a[i].val - a[j].val >= k) j ++;
        if (i > n)
        {
            ans = min(ans, {i - j, a[i].val});
        }
    }
    printf("%d %d\n", ans.first, ans.second % mod);
    int l = ans.second - k;
    int r = ans.second;
    for (int i = 1; i <= 2 * n; i ++)
    {
        if (a[i].val > l && a[i].val < r)
        {
            printf("%d ", a[i].id);
        }
    }
    
    puts("");
}

int main()
{
    solve();
    return 0;
}