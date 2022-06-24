#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

int n, m;
char s[MAXN];
int a[MAXN];
int cnt[30];
int sum[MAXN][30];

void init() {
    for (int i = 0; i < 26; i++) cnt[i] = 0;

}

void solve() {
    n = read(), m = read();
    init();
    scanf("%s", s + 1);
    for (int i = 1; i <= m; i++) a[i] = read();

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            sum[i][j] = sum[i - 1][j];
            if (s[i] == (char)( 'a' + j))
                sum[i][j]++;
        }
    }

    for (int i = 1; i <= m; i++) {
        int u = a[i];
        for (int j = 0; j < 26; j++)
            cnt[j] += sum[u][j];
    }

    for (int j = 0; j < 26; j++) cnt[j] += sum[n][j];

    for (int i = 0; i < 26; i++) printf("%d ", cnt[i]);
    puts("");
}

int main() {
    int t = read();
    while (t--)
        solve();
    return 0;
}