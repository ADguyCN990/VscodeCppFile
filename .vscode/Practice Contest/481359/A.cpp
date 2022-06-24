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
int a[MAXN];
int n, m;
set<int> s;
map<int, int> cnt;
void solve() {
    n = read(), m = read();
    s.clear();
    cnt.clear();
    for (int i = 1; i <= n; i++) a[i] = read(), s.insert(a[i]), cnt[a[i]]++;
    while (m--) {
        int opt;
        opt = read();
        if (opt == 1) {
            int p = read(), x = read();
            cnt[a[p]]--;
            if (!cnt[a[p]])
                s.erase(a[p]);
            a[p] = x;
            s.insert(x);
            cnt[x]++;
        }
        else {
            if (cnt[0] > 0)
                printf("%d\n", s.size() - 1);
            else
                printf("%d\n", s.size());
        }
    }
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}