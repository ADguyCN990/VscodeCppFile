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
int f[MAXN], ff[MAXN];
ll siz[MAXN], sizz[MAXN];
int n;

int findx(int x) {
    if (x == f[x]) return x;
    return f[x] = findx(f[x]);
}

int ffindx(int x) {
    if (x == ff[x]) return x;
    return ff[x] = ffindx(ff[x]);
}

void solve() {
    int n = read(), m = read();
    int mx = 2000000;
    for (int i = 1; i <= mx; i++) {
        if ((n + (n % m) % m) == 0) {
            puts("Yes");
            return;
        }
        n = (n + (n % m)) % m;
    }
    puts("No");
}

int main() {
    solve();
    return 0;
}