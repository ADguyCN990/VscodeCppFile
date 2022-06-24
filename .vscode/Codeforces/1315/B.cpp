#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define int long long
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int a, b, p;
int n;
char s[MAXN];

bool check(int mid) {
    int cnt = 0;
    if (s[mid] == 'A') cnt += a;
    else cnt += b;
    for (int i = mid + 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            if (s[i] == 'A') cnt += a;
            else cnt += b;
        }
    }
    return cnt <= p;
}

void solve() {
    a = read(), b = read(), p = read();
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int l = 1, r = n;
    int ans = n;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    
    printf("%d\n", ans);
}

signed main() {
    int t = read();
    while (t--)
        solve();
    return 0;
}