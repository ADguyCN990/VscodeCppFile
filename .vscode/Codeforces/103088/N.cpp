#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
int y, n;
struct node
{
    int l, r, val;
} tr[MAXN * 40];
int top = 0;
int root[MAXN] ,a[MAXN],b[MAXN];
int build(int node, int l, int r)
{
    node = ++top;
    if (l == r)
    {
        return node;
    }
    int mid = (l + r) / 2;
    tr[node].l = build(tr[node].l, l, mid);
    tr[node].r = build(tr[node].r, mid + 1, r);
    return node;
}
int upd(int l, int r, int node, int x)
{
    int cur = ++top;
    tr[cur] = tr[node];
    tr[cur].val++;
    if (l == r)
    {
        return cur;
    }
    int mid = (l + r) / 2;
    if (x > mid)
        tr[cur].r = upd(mid + 1, r, tr[node].r, x);
    else
        tr[cur].l = upd(l, mid, tr[node].l, x);
    return cur;
}
int query(int l, int r, int x, int lr, int rr)
{
    if (l == r)
        return tr[rr].val - tr[lr].val;
    int sum = 0;
    int mid = (l + r) / 2;
    if (x <= mid)
        sum = query(l, mid, x, tr[lr].l, tr[rr].l) + tr[tr[rr].r].val - tr[tr[lr].r].val;
    else
        sum = query(mid + 1, r, x, tr[lr].r, tr[rr].r);
    return sum;
}
signed main()
{
    scanf("%d%d", &y, &n);
    for (int i = 1; i <= y; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b + 1, b + y + 1);
    root[0] = build(0, 1, MAXN);
    for (int i = 1; i <= y; i++)
        root[i] = upd(1, MAXN, root[i - 1], a[i]);
    for (int i = 1; i <= n; i++)
    {
        int aa, p, f;
        scanf("%d%d%d", &aa, &p, &f);
        if (p <= a[aa] || p > b[y])
        {
            printf("0\n");
            continue;
        }
        int ans = query(1, MAXN, p, root[aa], root[aa + f]);
        printf("%d\n", ans);
    }
    return 0;
}