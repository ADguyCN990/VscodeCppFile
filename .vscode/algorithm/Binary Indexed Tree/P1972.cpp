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
int a[MAXN], c[MAXN], n, m, ans[MAXN];
map <int, int> last;
struct node
{
    int l, r, id;
}q[MAXN];
bool cmp(node a, node b) {return a.r < b.r;}

int lowbit(int x) {return x & -x;}

void add(int x, int k)
{
    for (int i = x; i <= n; i += lowbit(i)) c[i] += k;
}

int ask(int x)
{
    int ans = 0;
    for (int i = x; i; i -= lowbit(i)) ans += c[i];
    return ans;
}

void solve()
{
    n = read();
    for (int i = 1; i <= n; i ++) a[i] = read();
    m = read();
    for (int i = 1; i <= m; i ++)
    {
        q[i].l = read(), q[i].r = read();
        q[i].id = i;
    }
    sort(q + 1, q + 1 + m, cmp);
    int now = 1; //当前区间更新范围：[now, r]
    for (int i = 1; i <= m; i ++)
    {
        for (int j = now; j <= q[i].r; j ++)
        {
            if (!last.count(a[j]))
            {
                add(j, 1);
            }
            else
            {
                add(last[a[j]], -1);
                add(j, 1);
            }
            last[a[j]] = j;
        }
        ans[q[i].id] = ask(q[i].r) - ask(q[i].l - 1);
        now = q[i].r + 1;
    }
    for (int i = 1; i <= m; i ++)
    {
        printf("%d\n", ans[i]);
    }
}

int main()
{
    solve();
    return 0;
}