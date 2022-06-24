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
    ll n;
    n = read();
    ll a = 1234567;
    ll b = 123456;
    ll c = 1234;
    for (ll i = 0; i <= 200; i++) {
        for (ll j = 0; j <= 20000; j++) {
            if (i * a + j * b <= n) {
                ll rem = n - i * a - j * b;
                if (rem % c == 0) {
                    puts("YES");
                    return;
                }
            }
        }
    }
    puts("NO");
}

int main() {
    solve();
    return 0;
}