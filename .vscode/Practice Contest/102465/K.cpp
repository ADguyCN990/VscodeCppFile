#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
typedef pair<unsigned long long, unsigned long long> puu;

int n;
const int N = 700 + 5;
ull M = 11451449, M2 = 998244353;
int f[N][N];
int ok[N][N];
char s[N];
ull h[N], p[N], h2[N], p2[N];
ull P = 2333;

ull get1(int l, int r){
    return (h[r] % M - h[l - 1] * p[r - l + 1] % M + M) % M;
}
ull get2(int l, int r){
    return (h2[r] % M2 - h2[l - 1] * p2[r - l + 1] % M2 + M2) % M2;
}

puu query(int l, int r){
    return puu(get1(l, r), get2(l, r));
}

void init();

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> s + 1;
    init();
    
    for (int len=2;len<=n;++len){
        for (int i=1;i<=n;++i){
            int j = i + len - 1;
            if (j > n) continue;

            for (int k=i;k<j;++k){
                f[i][j] = min(f[i][j], f[i][k] + f[k+1][j]);
                int len1 = (k - i + 1) / ok[i][k], len2 = (j - k) / ok[k + 1][j];
                if (len1 == len2 && query(i, i + len1 - 1) == query(k + 1, k + len2)){
                    if (f[i][j] > f[i][k]){
                        f[i][j] = f[i][k]; ok[i][j] = ok[i][k] + ok[k + 1][j];
                    }
                }
            }
        }
    }

    cout << f[1][n] << endl;

    return 0;
}

void init(){
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            ok[i][j] = 1;
            f[i][j] = j - i + 1;
        }
    }
    for (int i=1;i<=n;++i){
        f[i][i] = 1;
    }
    p[0] = 1;
    p2[0] = 1;
    for (int i=1;i<=n;++i){
        h[i] = (h[i - 1] * P % M + (s[i] )) % M;
        h2[i] = (h2[i - 1] * P % M2 + (s[i] )) % M2;
        // h[i] = (h[i - 1] * P % M + (s[i] - 'a' + 1 )) % M;
        // h2[i] = (h2[i - 1] * P % M2 + (s[i] - 'a' + 1 )) % M2;
        p[i] = p[i - 1] * P % M;
        p2[i] = p2[i - 1] * P % M2;
    }
}