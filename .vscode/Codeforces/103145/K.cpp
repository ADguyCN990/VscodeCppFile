#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define MAXM 200005
typedef pair<int, int> pii;
int read() {
    int x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
ll f[MAXN], siz[MAXN];
ll ans[MAXM];
struct node {
    int u, v, val;
    friend bool operator< (node a, node b) {
        return a.val > b.val;
    }
}e[MAXM];

struct query {
    int mn;
    int id;
    friend bool operator< (query a, query b) {
        return a.mn > b.mn;
    }
}q[MAXM];

int findx(int x) {
    if (x == f[x]) return x;
    return f[x] = findx(f[x]);
}

void merge(int x, int y) {
    int fx = findx(x);
    int fy = findx(y);
    if (fx != fy) {
        siz[fx] += siz[fy];
        f[fy] = fx;
    }
}

int n, m, k;

void init() {
    for (int i = 1; i <= n; i++) f[i] = i, siz[i] = 1;
}

void solve() { 
    n = read(), m = read(), k = read();
    init();
    for (int i = 1; i <= m; i++) {
        e[i].u = read(), e[i].v = read(), e[i].val = read();
    }
    sort(e + 1, e + 1 + m);
    for (int i = 1; i <= k; i++) {
        q[i].mn = read();
        q[i].id = i;
    }
    sort(q + 1, q + 1 + k);
    int pos = 1;
    ll res = 0;
    for (int i = 1; i <= k; i++) {
        int mn = q[i].mn;
        // if (mn < e[m].val) {
        //     ans[q[i].id] = res;
        //     continue;
        // }
        for (int j = pos; j <= m; j++) {
            if (e[j].val < mn) { //destroyed
                pos = j;
                break;
            }
            int x = e[j].u, y = e[j].v;
            int fx = findx(x);
            int fy = findx(y);
            if (fx != fy) {
                //res -= siz[fx] * (siz[fx] - 1) / 2 + siz[fy] * (siz[fy] - 1) / 2;
                res += siz[fx] * siz[fy];
                siz[fx] += siz[fy];
                f[fy] = fx;   
            }
        
        }
        ans[q[i].id] = res;
    }
    for (int i = 1; i <= k; i++)
        printf("%lld\n", ans[i]);
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}