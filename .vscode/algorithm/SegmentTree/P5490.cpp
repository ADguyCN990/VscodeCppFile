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
int n; //矩形个数
struct segment //扫描线信息
{
    ll x, y1, y2;
    int k; //区分一个矩形中的两个线段
}seg[MAXN << 1]; //MAXN 表示矩形个数，乘以2才表示线段
bool cmp(segment a, segment b)
{
    return a.x < b.x;
}
struct node //线段树节点表示的是区间不是节点
{
    int l, r, cnt; //cnt表示该段区间出现的次数，l和r表示左右两个子区间的序号
    ll len; //线段真正的长度，而非 r - l + 1，公式下面会推
}tree[MAXN << 3]; //一共有2n个区间所以要再乘以2

vector <ll> ys; //去重离散化，存放所有横坐标上点的位置，为了线段树的区间操作做准备
int findx(ll x) {return lower_bound(ys.begin(), ys.end(), x) - ys.begin();}

void pushup(int rt)
{
    //假设左区间的编号 = 0,右区间的编号 = 1;
    //y[0]为ys[0]到ys[1]的距离,表示0号区间的长度; y[1]为ys[1]到ys[2]的距离，表示1号区间的长度
    //当前区间的长度为 y[0]+y[1]=ys[1]-ys[0]+ys[2]-ys[1]=ys[2]-ys[0]
    //结论：tree[rt].len = ys[tree[rt].r + 1] - ys[tree[rt].l]
    if (tree[rt].cnt) tree[rt].len = ys[tree[rt].r + 1] - ys[tree[rt].l]; //整个区间都被覆盖
    else if (tree[rt].l != tree[rt].r) tree[rt].len = tree[rt << 1].len + tree[rt << 1 | 1].len;
    else tree[rt].len = 0; //叶子节点且未被覆盖
}

void build(int rt, int l, int r)
{
    tree[rt] = {l, r, 0, 0};
    if (l == r) return;
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
}

void update(int rt, int l, int r, int k) //l点到r点的出现次数+1
{
    if (tree[rt].l >= l && tree[rt].r <= r)
    {
        tree[rt].cnt += k;
        pushup(rt); //更新len
        return;
    }
    int mid = tree[rt].l + tree[rt].r >> 1;
    if (mid >= l) update(rt << 1, l, r, k);
    if (mid + 1 <= r) update(rt << 1 | 1, l, r, k);
    pushup(rt);
}

void solve()
{
    n = read();
    for (int i = 1, j = 0; i <= n; i ++)
    {
        ll x1, x2, y1, y2;
        x1 = read(), y1 = read(), x2 = read(), y2 = read();
        seg[++ j] = {x1, y1, y2, 1};
        seg[++ j] = {x2, y1, y2, -1};
        ys.pb(y1), ys.pb(y2);
    }
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end()); //离散化去重
    sort(seg + 1, seg + 1 + 2 * n, cmp); //将线段按纵坐标排序

    // 去重后y轴上一共有siz个节点，siz - 1个区间，对这些区间建树
    int siz = ys.size();
    build(1, 0, siz - 2);
    ll ans = 0;
    for (int i = 1; i <= 2 * n; i ++) //扫描线扫过去
    {
        if (i > 1) ans += tree[1].len * (seg[i].x - seg[i - 1].x);
        update(1, findx(seg[i].y1), findx(seg[i].y2) - 1, seg[i].k);

    }
    printf("%lld\n", ans);
}

int main()
{
    solve();
    return 0;
}