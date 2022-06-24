#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
const int N = 16 + 3, M = 200 + 5;
ll f[N][N][M], p[N];
int w[N];

void init(){
    p[0] = 1LL;
    for (int i=2;i<=17;++i){
        p[i] = p[i - 1] * 10LL;
    }
}

int main(void){
    scanf("%d%d", &n, &m);
    for (int i=1;i<=n;++i){
        scanf("%d", &w[i]);
    }
    sort(w + 1, w + 1 + n);
    init();

    f[0][0][0] = 0;
    for (int i=1;i<=n;++i){
        for (int j=0;j<i;++j){
            for (int k=0;k<m;++k){
                for (int a=0;a<=i;++a){
                    ll cur = f[i][j][k] / p[a] * p[a + 1] + p[a] * w[i] + f[i][j][k] % p[a];
                    f[i + 1][a][cur % m] = max(f[i + 1][a][cur % m], cur);
                }
            }
        }
    }
    ll res = 0;
    for (int i=m-1;i>=0;--i){
        for (int j=0;j<=n;++j){
            res = max(res, f[n][j][i]);
        }
        if (res > 0) break;
    }
    printf("%lld\n", res);

    return 0;
}