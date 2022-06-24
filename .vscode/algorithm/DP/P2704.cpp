#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
#define MAXM 200005
#define MXBIT (1 << 10) + 10
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

ll dp[MAXN][MXBIT][MXBIT][MXBIT];
int n, m;
char s[MAXN][MAXN];

bool judge(int row, int x) {
    if (x & (x >> 1) || x & (x >> 2) || x & (x << 1) || x & (x << 2)) return false;
    for (int i = 0; i < m; i++) 
        if ((x >> (m - 1 - i)) & 1 == 1 && s[row][i] == 'H') return false;
    return true;
}

bool check(int now, int last, int llast) {
    if (now & last) return false;
    if (now & llast) return false;
    if (last & llast) return false;
    return true;
}

void solve() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        scanf("%s", s);
    
}

int main() {
    solve();
    return 0;
}