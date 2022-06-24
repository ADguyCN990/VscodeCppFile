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
int rt[MAXN], idx;
int n, m;
struct node
{
    int l, r;
    char c;
}tree[MAXN << 5];
int build(int l, int r)
{
    int now = ++ idx;
    int mid = l + r >> 1;
    if (l < r)
    {
        tree[now].l = build(l, mid);
        tree[now].r = build(mid + 1, r);
    }
    return now;
}

int update(int pre, int L, int R, int pos, char c)
{
    int now = ++ idx;
    int mid = L + R >> 1;
    tree[now].l = tree[pre].l, tree[now].r = tree[pre].r, tree[now].c = tree[pre].c;
    if (L == R && L == pos)
    {
        tree[now].c = c;
        return now;
    }
    if (mid >= pos) tree[now].l = update(tree[pre].l, L, mid, pos, c);
    else tree[now].r = update(tree[pre].r, mid + 1, R, pos, c);
    return now;
}

char query(int rt, int L, int R, int pos)
{
    if (L == R && L == pos) return tree[rt].c;
    int mid = L + R >> 1;
    if (mid >= pos) return query(tree[rt].l, L, mid, pos);
    else return query(tree[rt].r, mid + 1, R, pos);
}
char opt[10];
int x;
void solve()
{
    n = 100000;
    m = read();
    rt[0] = build(1, n);
    int len = 0;
    int last = 0;
    for (int i = 1; i <= m; i ++)
    {
        scanf("%s", opt);
        if (opt[0] == 'T')
        {
            char s[10];
            scanf("%s", s);
            len ++;
            rt[i] = update(rt[i - 1], 1, n, len, s[0]);
        }
        else if (opt[0] == 'U')
        {
            int x = read();
            rt[i] = rt[i - x - last - 1];
            last = 0;
        }
        else
        {
            last ++;
            int x = read();
            rt[i] = rt[i - 1];
            printf("%c\n", query(rt[i], 1, n, x));
        }
    }
}

int main()
{
    solve();
    return 0;
}