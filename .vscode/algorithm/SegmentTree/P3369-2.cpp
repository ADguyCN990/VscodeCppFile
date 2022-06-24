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
int n;
#define base 10000001 //本题特殊，有负数，加上这个数是为了保证非负
#define LL 1 //区间范围下限
#define RR 20000001 //区间范围上限
int idx = 1; //用于权值线段树动态开点，必须预留一个位置给根节点
struct node //存放的l和r是左右子树的下标而非区间的范围
{
    int l, r, cnt; // cnt表示当前区间的数字出现的次数
}tree[MAXN << 2];

void pushup(int rt)
{
    tree[rt].cnt = tree[tree[rt].l].cnt + tree[tree[rt].r].cnt;
}

void update(int &rt, int L, int R, int val, int y) //L,R表示区间信息，一定要加引用
{
    if (!rt)   
    {
        rt = ++ idx;
        tree[rt] = {0, 0, 0};
    }
    if (L == R)
    {
        tree[rt].cnt += y;
        if (tree[rt].cnt < 0) tree[rt].cnt = 0;
        return;
    }
    int mid = L + R >> 1;
    if (val <= mid) update(tree[rt].l, L, mid, val, y);
    if (mid + 1 <= val) update(tree[rt].r, mid + 1, R, val, y);
    pushup(rt);
}

int query(int rt, int L, int R, int l, int r) //L,R表示区间信息，查询x的排名是多少
{
    if (!rt) return 0;
    if (L >= l && R <= r) return tree[rt].cnt;
    int mid = L + R >> 1;
    int ans = 0;
    if (l <= mid) ans += query(tree[rt].l, L, mid, l, r);
    if (mid + 1 <= r) ans += query(tree[rt].r, mid + 1, R, l, r);
    return ans;
}

int kth(int rt, int L, int R, int k)  //查询第k小的数是什么
{
    if (L == R) return L;
    int mid = L + R >> 1;
    if (tree[tree[rt].l].cnt >= k) return kth(tree[rt].l, L, mid, k);
    else return kth(tree[rt].r, mid + 1, R, k - tree[tree[rt].l].cnt);
}

int getpre(int rt, int x) //查找小于x的最大值
{
    int rk = query(1, LL, RR, LL, x - 1 + base);
    return kth(1, LL, RR, rk) - base;
}

int getnxt(int rt, int x) //查找大于x的最小值
{
    int rk = query(1, LL, RR, LL, x + base) + 1;
    return kth(1, LL, RR, rk) - base;
}

void solve()
{
    n = read();
    //输入有负数的存在
    for (int i = 1; i <= n; i ++)
    {
        int opt, x;
        opt = read(), x = read();
        int rt = 1;
        if (opt == 1) // 插入一个数
            update(rt, LL, RR, x + base, 1);         
        else if (opt == 2) //删除一个数
            update(rt, LL, RR, x + base, -1);          
        else if (opt == 3) //查询数值为x的数的排名
            printf("%d\n", query(1, LL, RR, LL, base + x - 1) + 1);
        else if (opt == 4) //查询排名为x的数的数值大小
            printf("%d\n", kth(1, LL, RR, x) - base);
        else if (opt == 5) //查找小于x的最大数
            printf("%d\n", getpre(1, x));
        else if (opt == 6) //查找大于x的最小数
            printf("%d\n", getnxt(1, x));
    }
}

int main()
{
    solve();
    return 0;
}