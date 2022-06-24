#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
#define MAXM 200005
#define mod 998244353
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
int n, m, x;
void solve() {
    n = read(), x = read(), m = read();
    int mn = x, mx = x;
    for (int i = 1; i <= m; i++) {
        int l = read(), r = read();
        if (l <= mn && r >= mx) {
            mn = l;
            mx = r;
        }
        else if (r >= mn && r <= mx && l < mn) {
            mn = l;
        }
        else if (l >= mn && l <= mx && r > mx) {
            mx = r;
        }
    }
    printf("%d\n", mx - mn + 1);

}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}