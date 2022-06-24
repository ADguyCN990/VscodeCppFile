#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
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
ll n;
char s[MAXN], t[MAXN];

bool check() {
    int cnt0 = 0, cnt1 = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0')
            cnt0++;
        else
            cnt1++;
        if (t[i] == '0')
            cnt0--;
        else
            cnt1--;
    }
    return !cnt0 && !cnt1;
}

void solve() {
    n = read();
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    bool flag = check();
    if (!flag) {
        puts("-1");
        return;
    }
    int dif = 0, mx = 0, mn = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == t[i]) continue;
        if (s[i] == '1')
            dif++;
        else 
            dif--;
        mx = max(mx, dif);
        mn = min(mn, dif);
    }
    printf("%d\n", mx - mn);
}

int main() {
    solve();
    return 0;
}