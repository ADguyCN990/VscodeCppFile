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
char s[MAXN];
int a[MAXN];
char ans[MAXN];
int cnt[MAXN];
int m, n;

void init() {
    memset(ans, 0, sizeof ans);
    memset(cnt, 0, sizeof cnt);
}

void solve() {
    init();
    scanf("%s", s + 1);
    n = strlen(s + 1);
    m = read();
    for (int i = 1; i <= m; i++) a[i] = read();
    for (int i = 1; i <= n; i++)
        cnt[s[i] - 'a']++;
    int now = 25, left = m;
    while (left) {
        static vector<int> pos;
        pos.clear();
        for (int i = 1; i <= m; i++) 
            if (!ans[i] && !a[i])
                pos.pb(i);
        while (cnt[now] < (int)pos.size())
            now--;
        for (int i = 0; i < (int)pos.size(); i++) 
            ans[pos[i]] = now + 'a';
        for (int i = 0; i < (int)pos.size(); i++) {
            int x = pos[i];
            for (int j = 1; j < x; j++) 
                if (!ans[j])
                    a[j] -= x - j;
            for (int j = x + 1; j <= m; j++)
                if (!ans[j])
                    a[j] -= j - x;
        }
        left -= (int)pos.size();
        now--;
    }
    puts(ans + 1);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}