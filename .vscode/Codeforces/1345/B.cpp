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
int m;
int a[MAXN];
void pre() {
    a[1] = 2;
    ll now = 2;
    for (int i = 2; i; i++) {
        now = a[i - 1] + 3 * i - 1;
        if (now > 1e9) {
            m = i - 1;
            return;
        }
        a[i] = now;
    }
}

int findx(int val) {
    int l = 1, r = m;
    int ans;
    while (l <= r) {
        int mid = l + r >> 1;
        if (a[mid] <= val) {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return ans;
}

void solve() {
    ll n = read();
    int cnt = 0;
    while (n >= 2) {
        cnt++;
        int pos = findx(n);
        n -= a[pos];
    }
    printf("%d\n", cnt);
}

int main() {
    int T;
    T = read();
    pre();
    //printf("%d\n", m);
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}