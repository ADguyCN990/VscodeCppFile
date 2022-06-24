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
    int n = read();
    if (n <= 3) {
        puts("-1");
        return;
    }
    if (n == 4) {
        puts("2 4 1 3");
        return;
    }
    if (n & 1) {
        for (int i = n; i >= 5; i -= 2) 
            printf("%d ", i);
        printf("2 4 1 3 ");
        for (int i = 6; i < n; i += 2) 
            printf("%d ", i);
        puts("");
    }
    else {
        for (int i = n - 1; i >= 5; i -= 2) 
            printf("%d ", i);
        printf("2 4 1 3 ");
        for (int i = 6; i <= n; i += 2)
            printf("%d ", i);
        puts("");
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