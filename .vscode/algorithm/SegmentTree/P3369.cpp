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
int n; //节点个数
vector <int> num; //离散化后的数据
int opt[MAXN], a[MAXN]; //离线存储操作
struct node // 基于二叉堆建树，而非指针
{
    int l, r, cnt; //值域[l,r](离散化后)里出现了cnt个数, l,r表示区间中的理论最值
}tree[MAXN << 2];

void pushup(int rt) 
{
    tree[rt].cnt = tree[rt << 1].cnt + tree[rt << 1 | 1].cnt;
}

void build(int rt, int l, int r)
{
    tree[rt] = {l, r, 0};
    if (l == r) return;
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
}

void update(int rt, int x, int y) //插入或删除一个值为x的数
{
    if(tree[rt].l == tree[rt].r)
    {
        tree[rt].cnt += y;
        return;
    }
    int mid = tree[rt].l + tree[rt].r >> 1;
    if (x <= mid) update(rt << 1, x, y);
    if (mid + 1 <= x) update(rt << 1 | 1, x, y);
    pushup(rt);
}

int getrank(int rt, int x) //查询值为x的数的排名，实则查询[1,x-1]已出现的数字的个数，相当于区间查询
{
    if (tree[rt].r < x) return tree[rt].cnt;
    int mid = tree[rt].l + tree[rt].r >> 1;
    int ans = getrank(rt << 1, x); //左边肯定有贡献，因为会取到最小值
    if (x > mid + 1) ans += getrank(rt << 1 | 1, x);
    return ans;
}

int kth(int rt, int k) //查询排名为k的数的大小
{
    if (tree[rt].l == tree[rt].r)
    {
        return tree[rt].l;
    }
    if (tree[rt << 1].cnt >= k) return kth(rt << 1, k); 
    else return kth(rt << 1 | 1, k - tree[rt << 1].cnt); //注意减去左子树的大小
}

int findmx(int rt) //区间中的实际最大值
{
    if (tree[rt].l == tree[rt].r) return tree[rt].r;
    if (tree[rt << 1 | 1].cnt) return findmx(rt << 1 | 1); //右子树中还有数
    else return findmx(rt << 1);
}

int findpre(int rt, int x) //查找最大的比x小的数是多少
{
    if (tree[rt].r < x)
    {
        if (tree[rt].cnt) return findmx(rt);
        else return 0;
    }
    int mid = tree[rt].l + tree[rt].r >> 1;
    if (x > mid + 1 && tree[rt << 1 | 1].cnt)
    {
        int ans = findpre(rt << 1 | 1, x); //按照值来看在右子树中
        if (ans) return ans; //右子树中不存在这个节点
    }
    return findpre(rt << 1, x); //在右子树找不到只能去左子树找
}

int findmn(int rt) //区间中的实际最小值
{
    if (tree[rt].l == tree[rt].r) return tree[rt].l;
    if (tree[rt << 1].cnt) return findmn(rt << 1);
    else return findmn(rt << 1 | 1);
}

int findnxt(int rt,int x) //查找最小的比x大的数
{
    if (tree[rt].l > x)
    {
        if(tree[rt].cnt) return findmn(rt);
        else return 0;
    }
    int mid = tree[rt].l + tree[rt].r >> 1;
    if (x < mid && tree[rt << 1].cnt)
    {
        int ans = findnxt(rt << 1, x);
        if (ans) return ans;
    }
    return findnxt(rt << 1 | 1, x);
}

int findx(int x)
{
    return lower_bound(num.begin(), num.end(), x) - num.begin();
}

void solve()
{
    n = read();
    num.pb(-1e8);
    for (int i = 1; i <= n; i ++)
    {
        opt[i] = read();
        a[i] = read();
        if (opt[i] != 4) //离线操作插入所有数字，4是查询排名没有出现可能未知的数字
            num.pb(a[i]);
    }
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    int siz = num.size(); //一共出现了多少数字
    build(1, 1, siz);
    for (int i = 1; i <= n; i ++)
    {
        int t = opt[i];
        if (t == 1) //插入x
            update(1, findx(a[i]), 1);
        else if (t == 2) //删除x
            update(1, findx(a[i]), -1);
        else if (t == 3) //查询x的排名
            printf("%d\n", getrank(1, findx(a[i])) + 1);
        else if (t == 4) //查询排名为x的数
            printf("%d\n", num[kth(1, a[i])]);
        else if (t == 5) //查询小于x的最大的数
            printf("%d\n", num[findpre(1, findx(a[i]))]);
        else if (t == 6) //查询大于x的最小的数
            printf("%d\n", num[findnxt(1, findx(a[i]))]);
    }

}

int main()
{
    solve();
    return 0;
}