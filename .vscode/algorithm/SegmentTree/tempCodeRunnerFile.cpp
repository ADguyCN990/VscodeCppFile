#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 500005
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
int n, idx = 1, rt = 1;
int LL = 1, RR = 1000000000;
struct node
{
    int l, r;
    ll cnt;
}tree[MAXN << 2];

void pushup (int rt) {tree[rt].cnt = tree[tree[rt].l].cnt + tree[tree[rt].r].cnt;}

void update(int &rt, int L, int R, int val, ll y)
{
    if (!rt)
    {
        rt = ++ idx;
    }
    if (L == R)
    {
        tree[rt].cnt += y;
        return;
    }
    int mid = L + R >> 1;
    if (val <= mid) update(tree[rt].l, L, mid, val, y);
    else update(tree[rt].r, mid + 1, R, val, y);
    pushup(rt);
}

ll query(int rt, int L, int R, int l, int r)
{
    if (L >= l && R <= r) return tree[rt].cnt;
    int mid = L + R >> 1;
    ll ans = 0;
    if (mid + 1 <= r) ans += query(tree[rt].r, mid + 1, R, l, r);
    if (l <= mid) ans += query(tree[rt].l, L, mid, l, r);
    return ans;
}

void solve()
{
    n = read();
    ll ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        int num = read();
        ans += query(rt, LL, RR, num + 1, RR);
        update(rt, LL, RR, num, 1);
    }
    printf("%lld\n", ans);
}

int main()
{
    solve();
    return 0;
}