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
bool st[MAXN];
int f[MAXN]; //钥匙的状态，i表示使用,i + m表示未使用
int a[2][MAXN]; //门对应的钥匙编号
ll n, m;

int findx(int x) {
    if (x == f[x]) return x;
    return f[x] = findx(f[x]);
}

void merge(int x, int y) {
    int fx = findx(x);
    int fy = findx(y);
    if (fx != fy)
        f[fy] = fx;
}

void solve() {
    //n扇门m把钥匙
    n = read(), m = read();
    for (int i = 1; i <= n; i++) {
        int x = read();
        if (x) st[i] = true;
        else st[i] = false;
    }
    for (int i = 1; i <= m; i++) f[i] = i, f[i + m] = i + m;
    for (int i = 1; i <= m; i++) {
        int k = read();
        while (k--) {
            int tmp = read(); //用i这个钥匙可以去开tmp这个门
            if (!a[0][tmp]) a[0][tmp] = i;
            else a[1][tmp] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (st[i]) {
            merge(a[0][i], a[1][i]);
            merge(a[0][i] + m, a[1][i] + m);
        }
        else {
            merge(a[0][i], a[1][i] + m);
            merge(a[0][i] + m, a[1][i]);
        }
    }
    for (int i = 1; i <= m; i++) {
        if (findx(i) == findx(i + m)) {
            puts("NO");
            return;
        }
    }
    puts("YES");
}

int main() {
    solve();
    return 0;
}