#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 400005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define pb emplace_back
int read()
{
    int x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

int n, m;
int a[MAXN];
struct node
{
    int l, r;
    int mxopt;
    int mx;
}tree[MAXN << 2];

void pushup(int rt)
{
    tree[rt].mxopt = tree[rt << 1].mxopt | tree[rt << 1 | 1].mxopt;
    tree[rt].mx = max(tree[rt << 1].mx, tree[rt << 1 | 1].mx); 
}

void build(int rt, int l, int r)
{
    tree[rt].l = l, tree[rt].r = r;
    if (l == r)
    {
        tree[rt].mxopt = a[l];
        tree[rt].mx = a[l];
        return;
    } 
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}

void update(int rt, int l, int r, int k)
{
    if (tree[rt].l == tree[rt].r)
    {
        tree[rt].mx = tree[rt].mx & k;
        tree[rt].mxopt = tree[rt].mxopt & k;
        return;
    }
    int mid = tree[rt].l + tree[rt].r >> 1;
    if (mid >= l && (tree[rt << 1].mxopt & k) < tree[rt << 1].mxopt) update(rt << 1, l, r, k);
    if (mid + 1 <= r && (tree[rt << 1 | 1].mxopt & k) < tree[rt << 1 | 1].mxopt) update(rt << 1 | 1, l, r, k);
    pushup(rt);
}

void change(int rt, int pos, int k)
{
    if (tree[rt].l == tree[rt].r && tree[rt].l == pos)
    {
        tree[rt].mx = k;
        tree[rt].mxopt = k;
        return;
    }
    int mid = tree[rt].l + tree[rt].r >> 1;
    if (pos <= mid) change(rt << 1, pos, k);
    if (mid + 1 <= pos) change(rt << 1 | 1, pos, k);
    pushup(rt);
}

int query(int rt, int l, int r)
{
    if (tree[rt].l >= l && tree[rt].r <= r) return tree[rt].mx;
    int ans = 0;
    int mid = tree[rt].l + tree[rt].r >> 1;
    if (mid >= l) ans = query(rt << 1, l, r);
    if (mid + 1 <= r) ans = max(ans, query(rt << 1 | 1, l, r));
    return ans;
}

void solve()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i ++) a[i] = read();
    build(1, 1, n);
    char s[10];
    int l, r;
    int k;
    while (m --)
    {
        scanf("%s", s);
        l = read(), r = read();
        if (s[0] == 'A')
        {
            k = read();
            update(1, l, r, k);
        }
        else if (s[0] == 'U')
        {
            change(1, l, r);
        }
        else
            printf("%d\n", query(1, l, r));
    }
}

int main()
{
    solve();
    return 0;
}