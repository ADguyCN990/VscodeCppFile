#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
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
int n;
int a[MAXN];

bool check() {
    int odd = 0, even = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] & 1)
            odd++;
        else
            even++;
    }
    if (n & 1 && even - odd == 1 || n % 2 == 0 && odd == even) return true;
    return false;
}

void solve() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    bool flag = check();
    if (!flag) {
        puts("-1");
        return;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int u = i & 1;
        int v = a[i] & 1;
        if (u + v != 1) {
            cnt++;
        }
    }
    if (cnt & 1)
        printf("%d\n", (cnt - 3) / 2 + 3);
    else
        printf("%d\n", cnt / 2);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}