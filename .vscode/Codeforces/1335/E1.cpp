#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 2005
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
int n;
int a[MAXN];
int sum[MAXN][30];
struct node {
    int id;
    int num;
};

void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 26; j++) {
            sum[i][j] = 0;
        }
    }
}

void solve() {
    n = read();
    init();
    for (int i = 1; i <= n; i++) a[i] = read();
    if (n == 1) {
        puts("1");
        return;
    }
    if (n == 2) {
        if (a[1] == a[2])
            puts("2");
        else
            puts("1");
        return;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 26; j++) {
            sum[i][j] = sum[i - 1][j];
            if (j == a[i])
                sum[i][j]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= 26; i++)
        ans = max(ans, sum[n][i]);
    for (int i = 2; i < n; i++) {
        for (int j = i; j < n; j++) {
            //[1,i-1][i,j][j+1,n]
            int mid = 0, side = 0;
            for (int k = 1; k <= 26; k++) {
                if (!sum[i - 1][k] || !(sum[n][k] - sum[j][k])) continue;
                int num = min(sum[i - 1][k], sum[n][k] - sum[j][k]) * 2;
                if (num > side) {
                    side = num;
                }
            }
            for (int k = 1; k <= 26; k++) {
                int num = sum[j][k] - sum[i - 1][k];
                if (!num) continue;
                if (num > mid) {
                    mid = num;
                }
            }
            if (side + mid > ans) {
                // printf("%d %d\n", i, j);
                // printf("side: %d mid: %d\n", side, mid);
                ans = side + mid;
            }
        }
    }
    
    // if (sidefi.id != midfi.id) {
    printf("%d\n", ans);
    // }
    // else {
    //     printf("%d\n", max(sidefi.num + midse.num, sidese.num + midfi.num));
    // }
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i++) {
        solve();
    }

    return 0;
}