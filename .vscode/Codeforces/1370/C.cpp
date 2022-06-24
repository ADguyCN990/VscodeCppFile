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
    //Ashishgup先手
    if (n == 1) {
        puts("FastestFinger");
        return;
    }   
    if (n == 2) {
        puts("Ashishgup");
        return;
    }
    if (n & 1) {
        puts("Ashishgup");
        return;
    }
    vector<int> fac;
    int x = n;
    for (int i = 2; i <= x / i; i ++) {
        while (x % i == 0) {
            fac.pb(i);
            x /= i;
        }
    }
    if (x > 1) fac.pb(x);
    int cnt = 0;
    int even = 0;
    for (int i = 0; i < fac.size(); i++) {
        if (fac[i] & 1)
            cnt ++;
        else 
            even ++;
    }
        
    if (cnt == 1 && even == 1 || cnt == 0) {
        puts("FastestFinger");
        return;
    }
    puts("Ashishgup");
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}