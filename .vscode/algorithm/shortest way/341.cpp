#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define MAXM 2000005

int n, m;
int price[MAXN];
int h[MAXN], rh[MAXN], e[MAXM], ne[MAXM], cnt;
int dmin[MAXN], dmax[MAXN];
bool st[MAXN];

void add(int *h, int a, int b)
{
    e[cnt] = b, ne[cnt] = h[a], h[a] = cnt++;
}

void spfa(int *d, int start, int *h, bool flag)
{
    queue<int> q;
    memset(st, 0, sizeof st);
    if (flag)  memset(d, 0x3f, sizeof dmin);
    q.push(start);
    st[start] = true;
    d[start] = price[start];
    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (flag && d[j] > min(d[t], price[j]) || !flag && d[j] < max(d[t], price[j]))
            {
                if (flag) d[j] = min(d[t], price[j]);
                else d[j] = max(d[t], price[j]);
                if (!st[j])
                {
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);
    memset(rh, -1, sizeof rh);

    for (int i = 1; i <= n; i++)
        scanf("%d", &price[i]);
    while (m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(h, a, b), add(rh, b, a);
        if (c == 2)
            add(h, b, a), add(rh, a, b);
    }

    spfa(dmin, 1, h, true);
    spfa(dmax, n, rh, false);

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
         res = max(res, dmax[i] - dmin[i]);
         cout<<"min: "<<dmin[i]<<" max: "<<dmax[i]<<endl;
    }
       

    printf("%d\n", res);

    return 0;
}
