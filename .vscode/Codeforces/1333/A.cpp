#include<bits/stdc++.h>
using namespace std;
#define MAXN 105
#define ll long long
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
ll n, m;

void solve() {
    n = read(), m = read();
    if ((n * m) & 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int num = i + j & 1;
                if (num)
                    printf("W");
                else
                    printf("B");
            }
            puts("");
        }
    }
    else {
        if (n + m & 1) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    int num = i + j & 1;
                    if (i == n && j == m) 
                        printf("B");
                    else {
                        if (num)
                            printf("W");
                        else
                            printf("B");
                    }
                }
                puts("");
            }
        }
        else {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    int num = i + j & 1;
                    if (i == n && j == m)
                        printf("B");
                    else {
                        if (num)
                            printf("B");
                        else
                            printf("W");
                    }
                }
                puts("");
            }
        }
    }
}

int main() {
    int T = read();
    while (T--) {
        solve();
    }
}