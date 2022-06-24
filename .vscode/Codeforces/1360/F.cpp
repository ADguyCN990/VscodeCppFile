#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 15
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
char s[MAXN][MAXN];
int n, m;

bool check(char ans[]) {
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= m; j++) {
            if (ans[j] != s[i][j]) 
                cnt++;
        }
        if (cnt >= 2) return false;
    }
    return true;
}

void solve() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        scanf("%s", s[i] + 1);
    char ans[MAXN];
    memcpy(ans, s[1], sizeof ans);
    for (int i = 1; i <= m; i++) {
        bool flag = false;
        for (int j = 0; j < 26; j++) {
            ans[i] = 'a' + j;
            bool f = check(ans);
            if (f) {
                puts(ans + 1);
                return;
            }
        }
        ans[i] = s[1][i];
    }
    puts("-1");
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}