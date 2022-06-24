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
vector <int> num; //离散化用
int findx(int x) {return lower_bound(num.begin(), num.end(), x) - num.begin() + 1;} //离散化用
int n, m; //n个数据, m组询问
int a[MAXN]; //存放原始数据和离散化后结果
int rt[MAXN], idx; //不同的版本入口
struct node
{
    int l, r, cnt;
}tree[(MAXN << 2) + MAXN * 17]; //空间复杂度 O(原本size + nlog2n)

int build(int l, int r)
{
    int now = ++ idx;
    int mid = l + r >> 1;
    if (l < r)
    {
        tree[now].l = build(l, mid);
        tree[now].r = build(mid + 1, r);
    }
    tree[now].cnt = 0;
    return now;
}

int update(int pre, int L, int R, int k) //上一个版本变化的部分全部裂开成一条新的链，其他不变的继承上一个版本
{   
    int now = ++ idx;
    int mid = L + R >> 1;
    tree[now].l = tree[pre].l, tree[now].r = tree[pre].r, tree[now].cnt = tree[pre].cnt + 1;//继承
    if (L < R)
    {
        if (k <= mid) tree[now].l = update(tree[pre].l, L, mid, k); //裂开
        else if (mid + 1 <= k) tree[now].r = update(tree[pre].r, mid + 1, R, k); //裂开
    }
    return now;
}

int query(int l, int r, int L, int R, int k) //sum[r] - sum[l] 即为区间第k大值
{
    if (L == R) return L; //找到了这个数
    int mid = L + R >> 1;
    int sum = tree[tree[r].l].cnt - tree[tree[l].l].cnt;
    if (sum >= k)
        return query(tree[l].l, tree[r].l, L, mid, k);
    else 
        return query(tree[l].r, tree[r].r, mid + 1, R, k - sum);
}

void solve()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i ++) a[i] = read(),num.pb(a[i]);
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    for (int i = 1 ; i <= n; i ++)
        a[i] = findx(a[i]);
    int len = num.size();
    rt[0] = build(1, len);
    for (int i = 1; i <= n; i ++)
        rt[i] = update(rt[i-1], 1, len, a[i]);
    while (m --)
    {
        int l, r, k;
        l = read(), r = read(), k = read();
        int ans = query(rt[l - 1], rt[r], 1, len, k);
        printf("%d\n", num[ans - 1]);
    }
}

int main()
{
    solve();
    return 0;
}