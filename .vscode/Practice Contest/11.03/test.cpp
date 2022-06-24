#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m;
const int Max_n = 100 + 10;
ll f[Max_n][Max_n];

void init(){
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            f[i][j] = 0;
        }
    }
}

void flip(int x, int y){
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if (i%x==0 && j%y==0){
                f[i][j] = 1 - f[i][j];
            }
        }
    }
}

void solve(){
    init();
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            flip(i, j);
        }
    }
    int cnt = 0;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            // printf("%d ", f[i][j]);
            if (f[i][j]){
                cnt++;
            }
        }
        // printf("\n");
    }
    int sn = sqrt(n), sm = sqrt(m);
    if (cnt != sn*sm){
        printf("!!!     %d\n", cnt);
        printf("n: %d, m:%d \n", n, m);
    }
    // printf("!!!     %d\n", cnt);
}

int main(void){
    for (int i=1;i<=10;++i){
        for (int j=1;j<=10;++j){
            n = i, m = j;
            solve();
        }
    }
    return 0;
}