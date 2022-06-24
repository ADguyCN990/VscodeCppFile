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
int c[10000005];
int n, m, opt, l, r;
int lowbit(int x) {return x & -x;}

void update(int x, int val) {
    for (int i = x; i <= n; i += lowbit(i)) 
        c[i] += val;
}

int ask(int x) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i))
        ans += c[i];
    return ans;
}

void solve() {
    n = read(), m = read();
    while (m--) {
        opt = read();
        if (opt == 0) {
            l = read(), r = read();
            update(l, 1);
            if (r < n)
                update(r + 1, -1);
        }
        else {
            l = read();
            printf("%d\n", ask(l));
        }
    }
}

int main() {
    solve();
    return 0;
}