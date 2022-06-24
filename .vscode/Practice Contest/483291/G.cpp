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
int n, m;
int a[MAXN];
void solve() {
    m = read(), n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    sort(a + 1, a + 1 + n);
    for (int i = 1; i + 2 <= n; i++) {
        if (a[i + 1] == a[i] + 1 && a[i + 1] + 1 == a[i + 2]) {
            puts("NO");
            return;
        }
    }
    if (a[1] == 1 || a[n] == m) {
        puts("NO");
        return;
    }
    puts("YES");
}

int main() {
    solve();
    return 0;
}