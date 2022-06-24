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
void solve() {
    ll n = read(), k = read();
    if (n & 1) {
        if (k > n) { 
            puts("NO");
            return;
        }
        if (k % 2 == 0) {
            puts("NO");
            return;
        }
        puts("YES");
        for (int i = 1; i < k; i++) printf("1 ");
        printf("%lld\n", n - k + 1);
    }
    else {
        if (k & 1) {
            if (2 * k > n) {
                puts("NO");
                return;
            }
            puts("YES");
            for (int i = 1; i < k; i++) printf("2 ");
            printf("%lld\n", n - 2 * k + 2);
        }   
        else {
            if (k > n) {
                puts("NO");
                return;
            }
            puts("YES");
            for (int i = 1; i < k; i++) printf("1 ");
            printf("%lld\n", n - k + 1);
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