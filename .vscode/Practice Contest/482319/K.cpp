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
int n, k;
int cnt[MAXN];
int a[MAXN];

void solve() {
    n = read(), k = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= 100000; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++) cnt[a[i]]++;
    for (int i = 1; i <= k; i++) {
        if (k % i == 0) {
            if (i == k / i && cnt[i] > 1) {
                printf("%d %d\n", i, i);
                return;
            }
            else if (i != k / i && cnt[i] > 0 && cnt[k / i] > 0) {
                printf("%d %d\n", i, k / i);
                return;
            }
        }
    }
    puts("-1");
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}