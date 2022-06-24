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
    int zero, one, two;
    zero = read(), one = read(), two = read();
    if (zero && !one && two) {
        //101
        for (int i = 1; i <= zero + 1; i++) printf("0");
        for (int i = 1; i <= two + 1; i++) printf("1");
        puts("");
        return;
    }
    else if (zero && !one && !two) {
        //100
        for (int i = 1; i <= zero + 1; i++) printf("0");
        puts("");
        return;
    }
    else if (!zero && !one && two) {
        //001
        for (int i = 1; i <= two + 1; i++) printf("1");
        puts("");
        return;
    }
    else if (!zero && one && !two) {
        //010
        int u;
        for (int i = 1; i <= one + 1; i++) {
            u = i & 1 ^ 1;
            printf("%d", u);
        }
        puts("");
        return;
    }
    else if (zero && one && !two) {
        //110
        int u;
        for (int i = 1; i <= zero; i++) printf("0");
        for (int i = 1; i <= one + 1; i++) {
            u = i & 1 ^ 1;
            printf("%d", u);
        }
        puts("");
        return;
    }
    else if (!zero && one && two) {
        //011
        int u;
        for (int i = 1; i <= two + 1; i++) printf("1");
        for (int i = 1; i <= one; i++) {
            u = i & 1 ^ 1;
            printf("%d", u);
        }
        puts("");
        return;
    }
    //111
    for (int i = 1; i <= zero + 1; i++) printf("0");
    for (int i = 1; i <= two + 1; i++) printf("1");
    int u;
    for (int i = 1; i < one; i++) {
        u = i & 1 ^ 1;
        printf("%d", u);
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