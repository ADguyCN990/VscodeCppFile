#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 500005
typedef pair<int, int> pii;
int dx[6] = {0, 1, 1, 0, -1, -1};
int dy[6] = {1, 0, -1, -1, 0, 1};
int f[MAXN];
map<pii, int> id;
int cnt = 1;
ll siz[MAXN];

void build(pii p) {
    id[p] = ++cnt;
    f[cnt] = cnt;
    siz[cnt] = 6;
}

int findx(int x) {
    if (x == f[x]) return x;
    return f[x] = findx(f[x]);
}

void merge(int x, int y) {
    int fx = findx(x);
    int fy = findx(y);
    if (fx != fy) {
        siz[fx] += siz[fy] - 2;
        f[fy] = fx;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    //for (int i = 1; i <= n; i++) f[i] = i;
    while (n--) {
        int opt;
        scanf("%d", &opt);
        if (opt == 1) {
            //合并
            int x, y;
            scanf("%d%d", &x, &y);
            build(make_pair(x, y));
            for (int i = 0; i < 6; i++) {
                int a = x + dx[i], b = y + dy[i];
                if (!id.count({a, b})) continue;
                int now = findx(id[{x, y}]);
                int to = findx(id[{a, b}]);
                if (to == now) 
                    siz[now] -= 2;
                else
                    merge(now, to);
            }
        }
        else {
            //查询
            int x, y;
            scanf("%d%d", &x, &y);
            printf("%lld\n", siz[findx(id[{x, y}])]);
        }
    }
    return 0;
}