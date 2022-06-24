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
char s[MAXN];
int cnt[30];
void solve() {
    n = read(), k = read();
    memset(cnt, 0, sizeof cnt);
    scanf("%s", s + 1);
    sort(s + 1, s + 1 + n);
    for (int i = 1; i <= n; i++) {
        int u = s[i] - 'a';
        cnt[u]++;
    }
    int cntmn = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i]) {
            cntmn = cnt[i];
            break;
        }
    }
    if (cntmn < k) { //最小的数不够用
        printf("%c\n", s[k]);
    }
    else {
        printf("%c", s[1]);
        if (s[k + 1] == s[n]) {
            for (int i = k + 1; i <= n; i += k) printf("%c", s[i]);
        }
        else {
            for (int i = k + 1; i <= n; i++) printf("%c", s[i]);
        }
        puts("");
    }

}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}