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
    ll x = read();
    if (x % 10 == 0) {
        printf("%lld\n", x / 10);
        return;
    }
    if (x < 0) {
        x = -x;
        printf("%lld\n", -(x / 10 + 1));
    }
    else {
        printf("%lld\n", x / 10);
    }
    
}

int main() {
    solve();
    return 0;
}