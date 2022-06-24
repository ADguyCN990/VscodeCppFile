#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define per(i, x, y) for(int i = x; i >= y; i--)
#define pb emplace_back
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int a[MAXN];
void solve() {
    int n = read();
    int tmp;
    if (n & 1)
        tmp = n - 1;
    else 
        tmp = n;
    for (int i = 1; i <= n; i++) a[i] = n - i + 1;
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    puts("");
    if (n % 2 == 0) {
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (j == 1)
                    printf("%d ", a[i]);
                else if (j == i)
                    printf("%d ", tmp);
                else
                    printf("%d ", a[j]);
            }
            puts("");
        }
    }
    else {
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= n; j++)  {
                if (j == 2) {
                    if (i == 2) {
                        printf("%d ", a[1]);
                    }
                    else {
                        printf("%d ", a[i]);
                    }
                }
                else if (i == 2 && j == 1 || j == i)
                    printf("%d ", tmp);
                else 
                    printf("%d ", a[j]);
            }
            puts("");
        }
    }
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}