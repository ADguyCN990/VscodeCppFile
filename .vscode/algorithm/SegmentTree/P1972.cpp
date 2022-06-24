#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
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
ll n, m, l, r;
int a[MAXN];
int idx;
int rt[MAXN];
map <int, int> last;

struct node
{
    int l, r, cnt;
}tree[MAXN * 40];

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

int update(int pre, int L, int R, int pos, int y)
{
    int now = ++ idx;
    int mid = L + R >> 1;
    tree[now] = tree[pre], tree[now].cnt += y;
    if (L < R)
    {
        if (pos <= mid) tree[now].l = update(tree[pre].l, L, mid, pos, y);
        else tree[now].r = update(tree[pre].r, mid + 1, R, pos, y);
    }   
    return now;
}

int query(int now, int L, int R, int pos)
{
    if (L == R) return tree[now].cnt;
    int mid = L + R >> 1;
    if (pos <= mid)
    {
        return tree[tree[now].r].cnt + query(tree[now].l, L, mid, pos);
    }
    else return query(tree[now].r, mid + 1, R, pos);
}

void solve()
{
    n = read();
    for (int i = 1; i <= n; i ++) a[i] = read();
    rt[0] = build(1, n);
    for (int i = 1; i <= n; i ++)
    {
        if (!last.count(a[i]))
        {
            rt[i] = update(rt[i - 1], 1, n, i, 1);
        }
        else
        {
            int pre = update(rt[i - 1], 1, n, last[a[i]], -1);
            rt[i] = update(pre, 1, n, i, 1);
        }     
        last[a[i]] = i;    
    }
                                                                                                                                            
    m = read();
    while (m --)
    {
        l = read(), r = read();
        printf("%d\n", query(rt[r], 1, n, l));
    }
}

int main()
{
    solve();
    return 0;
}