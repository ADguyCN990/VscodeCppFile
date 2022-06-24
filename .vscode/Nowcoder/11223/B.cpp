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
int n;
int a[MAXN];
void solve() {
    n = read();
    set<int> s;
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        s.insert(a[i]);
        if (a[i] == 0) {
            puts("NO");
            return;
        }
    }
    sort(a + 1, a + 1 + n);
    if (s.size() >= 3 || s.size() == 1) {
        puts("YES");
        return;
    }
    if (s.size() == 2 && a[1] + a[n] != 0) {
        puts("YES");
        return;
    }
    if (s.size() == 2 && a[1] + a[n] == 0) {
        puts("NO");
    }
}

int main() {
    solve();
    return 0;
}