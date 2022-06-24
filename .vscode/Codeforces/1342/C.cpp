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
ll gcd(ll a,ll b)
{
    if(a<b) swap(a,b);
    ll tmp;
    while(b)
    {
       tmp=b;
       b=a%b;
       a=tmp; 
    }
    return a;
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
ll a, b, l, r, q;

ll get(ll n) {
    if (n == 0) return 0;
    if (a == b) return 0;
    ll cnt = n / lcm(a, b);
    ll tmp = n % lcm(a, b);
    if (cnt == 0) 
        return n - min(n, b - 1);
    ll num1 = b - 1;
    ll num2 = (cnt - 1) * b;
    ll num3 = min(tmp + 1, b);
    return n - num1 - num2 - num3;
}

void solve() {
    a = read(), b = read(), q = read();
    if (a > b) swap(a, b);
    while (q--) {
        l = read(), r = read();
        printf("%lld\n", get(r) - get(l - 1));

    }
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