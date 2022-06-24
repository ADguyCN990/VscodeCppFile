#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
typedef pair<int, int> pii;
int read() {
    int x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
pii a[MAXN];
int f[MAXN], siz[MAXN];
int n;
vector<int> num;
int ans;
int find(int x) {
    return lower_bound(num.begin(), num.end(), x) - num.begin() + 1;
}

void init() {
    for (int i = 1; i <= n; i++) f[i] = i, siz[i] = 1;
    num.clear();
    ans = 0;
}

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
        ans = max(ans, siz[fx]);
    }       
     
}

void solve() {
    n = read();
    init();
    for (int i = 1; i <= n; i++) {
        a[i].first = read(), a[i].second = read();
        num.push_back(a[i].first);
        num.push_back(a[i].second);
    }
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    for (int i = 1; i <= n; i++) {
        int u = find(a[i].first), v = find(a[i].second);
        merge(u, v);
    }
    printf("%d\n", ans);
}

int main() {
    int t;
    t = read();
    while (t--)
        solve();
    return 0;
}