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
ll gcd(ll a,ll b) {
    if(a<b) swap(a,b);
    ll tmp;
    while(b) {
       tmp=b;
       b=a%b;
       a=tmp; 
    }
    return a;
}
void solve() {
    ll n = read(), m = read();
    ll x = gcd(n, m);
    int ans = 1;
    for (ll i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            ans++;
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) ans++;
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}