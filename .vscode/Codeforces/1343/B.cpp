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
void solve() {
    ll n = read();
    if (n % 4) {
        puts("NO");
        return;
    }
    puts("YES");
    vector<int> odd, even;
    for (int i = 1, cnt = 1; cnt < n / 2; i += 2, cnt++) odd.pb(i);
    for (int i = 2, cnt = 1; cnt <= n / 2; i += 2, cnt++) even.pb(i);
    odd.pb(n - 1 + n / 2);
    for (int i = 0; i < even.size(); i++) printf("%d ", even[i]);
    for (int i = 0; i < odd.size(); i++) printf("%d ", odd[i]);
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