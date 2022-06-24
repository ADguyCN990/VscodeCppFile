#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 55
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
char s[MAXN][MAXN];
void solve() {
    n = read();
    for (int i = 1; i <= n; i++) 
        scanf("%s", s[i] + 1);
    for (int i = n; i >= 1; i--) {
        for (int j = n; j >= 1; j--) {
            if (i == n || j == n) continue;
            if (s[i][j] == '0') continue;
            if (s[i][j] == '1' && s[i + 1][j] == '0' && s[i][j + 1] == '0') {
                puts("NO");
                return;
            }
        }
    }
    puts("YES");
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}