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
ll a, b, n;

int check1(ll a, ll b) {
    //第一次给a加
    int cnt = 0;
    while (1) {
        if (a > n || b > n) 
            return cnt;
        cnt++;
        if (cnt & 1)
            a += b;
        else
            b += a;
    }
}

int check2(ll a, ll b) {
    //第一次给b加
    int cnt = 0;
    while (1) {
        if (a > n || b > n) 
            return cnt;
        cnt++;
        if (cnt & 1)
            b += a;
        else
            a += b;
    }
}

void solve() {
    a = read(), b = read(), n = read();
    int ans = INF;
    ans = min(ans, check1(a, b));
    ans = min(ans, check2(a, b));
    printf("%d\n", ans);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}