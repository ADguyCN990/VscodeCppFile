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
int n; //节点数量
int opt, x;
int root, idx; //有些操作要引用，定义root；idx就相当于链表操作
struct node //存放平衡树中的节点信息
{
    int l, r, cnt; //左右儿子编号，当前数出现次数
    int key, val; //BST和大根堆的权值
    int size; //子树大小
}tree[MAXN];

void pushup(int rt) //维护size
{
    tree[rt].size = tree[tree[rt].l].size + tree[tree[rt].r].size + tree[rt].cnt;
}

int new_node(int key) //新建一个节点，相当于new一个指针
{
    int now = ++idx;
    tree[now] = {0, 0, 1, key, rand(), 1};
    return idx;
}

void zag(int &p) //左旋
{
    int q = tree[p].r;
    tree[p].r = tree[q].l, tree[q].l = p, p = q;
    pushup(tree[p].l), pushup(p);
}

void zig(int &p) //右旋
{
    int q = tree[p].l;
    tree[p].l = tree[q].r, tree[q].r = p, p = q;
    pushup(tree[p].r), pushup(p); 
}

void build() //加两个哨兵，正无穷和负无穷防止越界
{
    new_node(-INF), new_node(INF);
    root = 1, tree[1].r = 2;
    pushup(root);
    if (tree[1].val < tree[2].val) zag(root); //满足堆的性质，旋转
}

void insert(int &now, int key) //插入一个值为key的值，因为涉及到根的修改所以加个引用
{
    if (!now) now = new_node(key); //走到叶子节点就新建一个
    else
    {
        if (key == tree[now].key) tree[now].cnt ++; //找到了相同的节点
        else if (key < tree[now].key)
        {
            insert(tree[now].l, key);
            if (tree[tree[now].l].val > tree[now].val) zig(now);
        } 
        else if (key > tree[now].key)
        {
            insert(tree[now].r, key);
            if (tree[tree[now].r].val > tree[now].val) zag(now); 
        }
    }
    pushup(now); //别忘了更新size
}

void remove(int &now, int key) //删除一个值为key的值，因为涉及到根的修改所以加个引用
{
    if (!now) return; //要删除的节点不存在，直接退出
    if (tree[now].key == key)
    {
        if (tree[now].cnt > 1) tree[now].cnt --;
        else //这个点直接没了
        {
            if (tree[now].l || tree[now].r) //判断是不是叶子节点
            {
                if (!tree[now].r && tree[tree[now].l].val)
                {
                    zig(now);
                    remove(tree[now].r, key);
                }
                else
                {
                    zag(now);
                    remove(tree[now].l, key);
                }
            }
            else now = 0; //叶子节点不用转来转去直接删
        }
    }
    else if (key > tree[now].key) remove(tree[now].r, key);
    else remove(tree[now].l, key);
    pushup(now); //别忘了更新size
}

int getrank(int rt, int key) //查询值为x的排名
{
    if (!rt) return 0;
    if (key == tree[rt].key) return tree[tree[rt].l].size + 1;
    else if (key < tree[rt].key) return getrank(tree[rt].l, key);
    else return getrank(tree[rt].r, key) + tree[tree[rt].l].size + tree[rt].cnt;
}

int kth(int rt, int k) //查询第k大的数
{
    if (!rt) return INF;
    if (tree[tree[rt].l].size >= k) return kth(tree[rt].l, k);
    else if (tree[tree[rt].l].size + tree[rt].cnt >= k) return tree[rt].key;
    else return kth(tree[rt].r, k - tree[tree[rt].l].size - tree[rt].cnt);
}

int getpre(int rt, int key) //查找小于key的最大数
{
    if (!rt) return -INF;
    if (key <= tree[rt].key) return getpre(tree[rt].l, key);
    else return max(tree[rt].key, getpre(tree[rt].r, key));
}

int getnxt(int rt, int key) //查找大于key的最小数
{
    if (!rt) return INF;
    if (key >= tree[rt].key) return getnxt(tree[rt].r, key);
    else return min(tree[rt].key, getnxt(tree[rt].l, key));
}

void solve()
{
    n = read();
    build(); //别忘了建树
    for (int i = 1; i <= n; i ++)
    {
        opt = read(), x = read();
        if (opt == 1) //插入一个数
            insert(root, x);
        else if (opt == 2) //删除一个数
            remove(root, x);
        else if (opt == 3) //查询一个数的排名
            printf("%d\n", getrank(root, x) - 1); //减一是因为插入了一个负无穷大的哨兵
        else if (opt == 4) //查询第k大的数
            printf("%d\n", kth(root, x + 1)); //同样是因为负无穷大的哨兵
        else if (opt == 5) //查询小于x的最大数
            printf("%d\n", getpre(root, x));
        else if (opt == 6) //查询大于x的最小数
            printf("%d\n", getnxt(root, x));
    }
}

int main()
{
    solve();
    return 0;
}