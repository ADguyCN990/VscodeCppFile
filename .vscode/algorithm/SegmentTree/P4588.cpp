#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
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
struct node
{
    int l, r;
    ll mul;
}tree[MAXN << 2];
ll m, mod;

void pushup(int rt) {tree[rt].mul = tree[rt << 1].mul * tree[rt << 1 | 1].mul % mod;}

void build(int rt, int l, int r)
{
    tree[rt].l = l, tree[rt].r = r, tree[rt].mul = 1;
    if (l == r) return;
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
}

void update(int rt, int pos, int val)
{
    if (tree[rt].l == tree[rt].r)
    {
        tree[rt].mul = val;
        return;
    }
    int mid = tree[rt].l + tree[rt].r >> 1;
    if (mid >= pos) update(rt << 1, pos, val);
    if (mid + 1 <= pos) update(rt << 1 | 1, pos, val);
    pushup(rt);
}

void solve()
{
    m = read(), mod = read();
    build(1, 1, m);
    for (int i = 1; i <= m; i ++)
    {
        int opt, x;
        opt = read(), x = read();
        if (opt == 1) 
            update(1, i, x);
        else 
            update(1, x, 1);
        tree[1].mul %= mod;
        printf("%lld\n", tree[1].mul);
    }
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