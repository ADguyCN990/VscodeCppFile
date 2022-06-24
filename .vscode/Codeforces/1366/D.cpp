#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 500005
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

int minfac[10000005];
void pre() {
    for (int i = 1; i <= 10000000; i++) minfac[i] = i;
    for (int i = 2; i * i <= 10000000; i ++) {
        if (minfac[i] == i) {
            for (int j = i * i; j <= 10000000; j += i) {
                minfac[j] = i;
            }
        }
    }
}

int n;
vector<int> a, b;
void solve() {
    n = read();
    for (int i = 1; i <= n; i++) {
        int x = read();
        int fac = minfac[x];
        int tmp = x;
        while (tmp % fac == 0)
            tmp /= fac;
        if (tmp == 1) {
            a.pb(-1);
            b.pb(-1);
        }
        else {
            a.pb(tmp);
            b.pb(x / tmp);
        }
    }
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    puts("");
    for (int i = 0; i < n; i++) printf("%d ", b[i]);
}

int main() {
    pre();
    solve();
    return 0;
}