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
ll n;
ll a[MAXN], b[MAXN];
void solve() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) b[i] = read();
    if (a[1] != b[1]) {
        puts("NO");
        return;
    }
    int x = n + 1, y = n + 1;//x表示正数，y表示负数
    a[n + 1] = 0, b[n + 1] = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > 0) {
            x = i;
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] < 0) {
            y = i;
            break;
        }
    }
    if (x < y) {
        for (int i = x + 1; i <= y; i++) {
            if (a[i] > b[i]) {
                puts("NO");
                return;
            }
        }
    }
    else {
        //[1,x-1]这段数中，a[i]>=b[i]
        for (int i = y + 1; i <= x; i++) {
            if (a[i] < b[i]) {
                puts("NO");
                return;
            }
        }
    }
    for (int i = 1; i <= min(x, y); i++) {
        if (a[i] != b[i]) {
            puts("NO");
            return;
        }
    }
    puts("YES");
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}