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
int n;
int a[MAXN];

void work(int l, int r) {
    for (int i = l, j = r; i <= j; i++, j--) {
        swap(a[i], a[j]);
    }
}

void solve() {
    n = read();
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == i) continue;
        if (a[i] != i && !l) {
            l = i;
        }
        if (l && a[i] == l) {
            r = i;
            break;
        }
    }
    //printf("l: %d r: %d\n", l , r);
    work(l, r);
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    puts("");
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}