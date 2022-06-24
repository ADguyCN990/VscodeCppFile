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
struct node
{
    int l, r, len, cnt, mxopt;
}tree[MAXN << 2];

void pushup(int rt) 
{
    tree[rt].cnt = tree[rt << 1].cnt + tree[rt << 1 | 1].cnt;
    tree[rt].mxopt = tree[rt << 1].mxopt + tree[rt << 1 | 1].mxopt;
}

void build(int rt, int l, int r)
{
    tree[rt] = {l, r, r - l + 1, 0, 0};
    int mid = l + r >> 1;
    if (l == r) return;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
}

void update(int rt, int l, int r)
{
    if (tree[rt].l == tree[rt].r)
    {
        //printf("!!! %d\n", tree[rt].l);
        tree[rt].cnt ++;
        tree[rt].mxopt ++;
        return;
    }
    int mid = tree[rt].l + tree[rt].r >> 1;
    if (mid >= l && tree[rt << 1].mxopt < tree[rt << 1].len) update(rt << 1, l ,r);
    if (mid + 1 <= r && tree[rt << 1 | 1].mxopt < tree[rt << 1 | 1].len) update(rt << 1 | 1, l ,r);
    pushup(rt);
}

void solve()
{
    n = read();
    build(1, 1, 100000);
    for (int i = 1; i <= n; i ++)
    {
        int x, y, xx, yy;
        x = read(), y = read(), xx = read(), yy = read();
        update(1, x + 1, xx);
    }
    printf("%d\n", tree[1].cnt);
}

int main()
{
    solve();
    return 0;
}