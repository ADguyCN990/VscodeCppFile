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
ll base[MAXN];
char s[15] ={'1', 'c', 'o', 'd', 'e', 'f', 'o', 'r', 'c', 'e', 's'};
int cnt[15];
void solve() {
    ll n = read();
    if (n == 1) {
        puts("codeforces");
        return;
    }
    ll now = 1;
    for (int i = 1; i <= 10; i++) cnt[i] = 1;
    while (1) {
        for (int i = 1; i <= 10; i++) {
            now /= cnt[i];
            cnt[i]++;
            now *= cnt[i];
            if (now >= n) break;
        }
        if (now >= n) break;
    }
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= cnt[i]; j++) {
            printf("%c", s[i]);
        }
    }
    puts("");
}

int main() {
    solve();
    return 0;
}