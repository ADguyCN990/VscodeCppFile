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
ll n, m, k;
ll a[MAXN], b[MAXN];
map<int, int> alice;
map<int, int> bob;
void solve() {
    n = read(), m = read(), k = read();
    for (int i = 1; i <= n; i++) a[i] = read(), alice[a[i]]++;
    for (int i = 1; i <= m; i++) b[i] = read(), bob[b[i]]++;
    if (n > m) {
        puts("YES");
        return;
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    for (int i = n, j = m; i > 0; i--, j--) {
        if (a[i] <= b[j]) continue;
        puts("YES");
        return;
    }
    puts("NO");

}

int main() {
    solve();
    return 0;
}