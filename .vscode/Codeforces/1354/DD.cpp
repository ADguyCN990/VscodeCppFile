#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
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
int n, q;
int c[MAXN];

int lowbit(int x) {
    return x & -x;
}

int ask(int x) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i)) {
        ans += c[i];
    }
    return ans;
}

int kth(int x) {
    int l = 1, r = n;
    int ans;
    while (l <= r) {
        int mid = l + r >> 1;
        if (ask(mid) >= x) {
            ans = mid;
            r = mid - 1;
        }
        else 
            l = mid + 1;
    }
    return ans;
}

void update(int x, int val) {
    for (int i = x; i <= n; i += lowbit(i)) 
        c[i] += val;
}

void solve() {
    n = read(), q = read();
    for (int i = 1; i <= n; i++) {
        int x = read();
        update(x, 1);
    }
    for (int i = 1; i <= q; i++) {
        int opt = read();
        if (opt > 0) {
            update(opt, 1);
        }
        else if (opt < 0) {
            opt = -opt;
            int num = kth(opt);
            update(num, -1);
        }
    }
    if (!ask(n)) {
        puts("0");
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (ask(i) - ask(i - 1) > 0) {
            printf("%d\n", i);
            return;
        }
    }
}

int main() {
    solve();
    return 0;
}