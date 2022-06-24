#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 1000, M = 500007, INF = 0x3f3f3f3f;
const double eps = 1e-4;

int ver[M], nex[M], edge[M], head[N], tot = 1;
int n; //这里的n是字符的个数
int m;
int q[N], cnt[N], vis[N];
double dist[N];

void add(int x, int y, int z)
{
    ver[++tot] = y;
    edge[tot] = z;
    nex[tot] = head[x];
    head[x] = tot;
}

bool check(double mid)
{
    memset(cnt, 0, sizeof cnt);
    memset(vis, 0, sizeof vis);

    int hh = 0, tt = 0;

    for (int i = 0; i < 676; ++i)
    {
        q[tt++] = i;
        vis[i] = true;
    }
    int counts = 0; //经验优化
    while (hh != tt)
    {
        int x = q[hh++];
        if (hh == N)
            hh = 0;
        vis[x] = false;

        for (int i = head[x]; ~i; i = nex[i])
        {
            int y = ver[i], z = edge[i];
            if (dist[y] < dist[x] + z - mid)
            {
                dist[y] = dist[x] + z - mid;
                cnt[y] = cnt[x] + 1;
                counts++;
                if (counts > 10000)
                    return true;
                if (cnt[y] >= N)
                    return true;
                if (!vis[y])
                {
                    vis[y] = true;
                    q[tt++] = y;
                    if (tt == N)
                        tt = 0;
                }
            }
        }
    }
    return false;
}



int main()
{
    while (scanf("%d", &n) && n)
    {
        memset(head, -1, sizeof head);
        tot = 1;
        for (int i = 1; i <= n; ++i)
        {
            char s[1010];
            scanf("%s", s);
            int len = strlen(s);

            if (len < 2)
                continue;
            int a = (s[0] - 'a') * 26 + s[1] - 'a';
            int b = (s[len - 2] - 'a') * 26 + s[len - 1] - 'a';
            add(a, b, len);
        }
        if (!check(0))
            puts("No solution");
        else
        {
            double l = 0, r = 1000;
            while (r - l > eps)
            {
                double mid = (l + r) / 2;
                if (check(mid))
                    l = mid;
                else
                    r = mid;
            }
            printf("%lf\n", r);
        }
    }
    return 0;
}
