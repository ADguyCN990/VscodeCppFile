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

ll inv(ll m, ll k) {
    ll res = 1 , t = m;
    ll mod = k + 2;
    while (k) {
        if (k&1) res = res * t % mod   ;
        t = t * t  % mod   ;
        k >>= 1;
    }
    return res;
}

void solve() {
    ll n = read();
    ll p = read();
    for (int i = 1; i <= n; i++)
        cout << inv(i, p - 2) << "\n";
}

int main() {
    solve();
    return 0;
}