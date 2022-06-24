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
char s[105];
char t[105];
int n;
void solve() {
    n = read();
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) t[i] = '.';
    for (int i = 1; i <= n; i++) {
        t[i] = s[i];
        if (i == 1 && s[2] == '*') t[1] = '*';
        if (i == n && s[n - 1] == '*') t[n] = '*';
        if (i > 1 && i < n && (s[i - 1] == '*' || s[i + 1] == '*')) t[i] = '*';
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (t[i] == '*') continue;
        int j = i;
        int cnt = 0;
        while (t[j] == '.' && j <= n) 
            cnt++, j++;
        ans += (cnt + 2) / 3;
        i = j - 1;
    }
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