#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define per(i, x, y) for (int i = x; i >= y; i--)
#define pb emplace_back
ll read()
{
    ll x = 0, f = 1;
    char ch;
    do
    {
        ch = getchar();
        if (ch == '-')
            f = -1;
    } while (ch < '0' || ch > '9');
    do
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    } while (ch >= '0' && ch <= '9');
    return x * f;
}
int f[10][10][10][10][10]; //状态
int n, m, cnt;
vector<pair<int, int>> vc[10010];              //存优惠方案
int id[100010], w[10], v[10], t[10], s[10010]; //各种值
void solve() {
    n = read();
    for (int i = 1; i <= n; i++) {
        int k;
        k = read();
        for (int j = 1; j <= k; j++) {
            int x, y;
            x = read(), y = read();
            if (!id[x])
                id[x] = ++cnt;                    //存是第几个数，可以是任何顺序
            vc[i].push_back(make_pair(id[x], y)); //存方案
        }
        s[i] = read();
    }
    m = read();
    for (int i = 1, x, k, p; i <= m; i++) {
        x = read(), k = read(), p = read();
        if (!id[x])
            id[x] = ++cnt;          //这里也要再存一遍
        v[id[x]] = k, w[id[x]] = p; //个数、价钱
    }
    for (int i = 0; i <= v[1]; i++) {
        for (int j = 0; j <= v[2]; j++) {
            for (int k = 0; k <= v[3]; k++) {
                for (int l = 0; l <= v[4]; l++) {
                    for (int o = 0; o <= v[5]; o++) {                                                                            //五层枚举
                        f[i][j][k][l][o] = i * w[1] + j * w[2] + k * w[3] + l * w[4] + o * w[5]; //没有优惠时
                        for (int I = 1; I <= n; I++) {
                            int t[6] = {0};
                            for (int J = 0; J < vc[I].size(); J++) {
                                t[vc[I][J].first] = vc[I][J].second; //每种的个数
                            }
                            if (i < t[1] || j < t[2] || k < t[3] || l < t[4] || o < t[5])
                                continue; //是否可行
                            f[i][j][k][l][o] =
                                min(f[i][j][k][l][o], f[i - t[1]][j - t[2]][k - t[3]][l - t[4]][o - t[5]] + s[I]); //状态转移
                        }
                    }
                }
            }
        }
    }
    printf("%d", f[v[1]][v[2]][v[3]][v[4]][v[5]]);
}

int main() {
    solve();
    return 0;
}