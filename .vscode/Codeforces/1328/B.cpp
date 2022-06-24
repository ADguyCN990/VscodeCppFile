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
int n, k;
// int findx(int x) {
//     for (int i = 1; i <= cnt; i++) {
//         if (x > pre[i - 1] && x <= pre[i])
//             return i;
//     }
//     return 0;
// }

// void prework() {
//     int now = 1;
//     for (int i = 1; ; i++) {
//         pre[i] = pre[i - 1] + now;
//         if (pre[i] > 100000) return;
//         cnt++;
//         now++;
//     }
// }

void solve() {
    n = read(), k = read();
    ll now = 1;
    ll sum = 0;
    int x, mod;
    for (int i = 1; ; i++) {
        sum += now;
        if (k <= sum) {
            x = i;
            mod = k - (sum - now);
            break;
        }
        now++;
    }
    //int x = findx(k);
    //int num = pre[x - 1];
    //int mod = k - num;
    //printf("x: %d mod: %d\n", x, mod);
    int pos1 = n - x;
    int pos2 = n - mod + 1;
    for (int i = 1; i <= n; i++) {
        if (i == pos1 || i == pos2)
            printf("b");
        else
            printf("a");
    }
    puts("");
}

int main() {
    int T;
    T = read();
    //prework();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}