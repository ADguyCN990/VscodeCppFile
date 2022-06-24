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
ll n;
ll a[MAXN];
ll res[MAXN];
vector <int> wa[MAXN];
ll gcd(ll a,ll b)
{
    if(a<b) swap(a,b);
    ll tmp;
    while(b)
    {
       tmp=b;
       b=a%b;
       a=tmp; 
    }
    return a;
}

struct node
{
    int l, r;
    ll val;
}tree[MAXN << 2];

void pushup(int rt)
{
    tree[rt].val = gcd(tree[rt << 1].val, tree[rt << 1 | 1].val);
}

void build(int rt, int l, int r)
{
    tree[rt].l = l, tree[rt].r = r;
    if (l == r)
    {
        tree[rt].val = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}

ll query(int rt, int l, int r)
{
    if (tree[rt].l >= l && tree[rt].r <= r)
    {
        return tree[rt].val;
    }
    int mid = tree[rt].l + tree[rt].r >> 1;
    ll ans = 0;
    if (l <= mid) ans = gcd(ans, query(rt << 1, l, r));
    if (mid + 1 <= r) ans = gcd(ans, query(rt << 1 | 1, l, r));
    return ans;
}

void solve()
{
    n = read();
    for (int i = 1; i <= n; i ++) a[i] = read();
    build(1, 1, n);
    for (int i = 1; i <= n; i ++)
    {
        int l = i + 1, r = n;
        int ans = i;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (query(1, i, mid) >= mid - i + 1)
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        //printf("i: %d ans: %d\n", i, ans);
        if (ans - i + 1 == query(1, i, ans)) 
        {
            wa[ans].pb(i);
            //printf("len: %d pos: %d\n", ans - i + 1, i);
        }
    }
    int cnt = -1;
    for (int i = 1; i <= n; i ++)
    {
        res[i] = res[i - 1];
        int x = wa[i].empty() ? -1 : wa[i][0];
        if (x > cnt)
        {
            res[i] ++;
            cnt = i;
        }
    }
    for (int i = 1; i <= n; i ++) printf("%lld ", res[i]);
    puts("");
}

int main()
{
    solve();
    return 0;
}