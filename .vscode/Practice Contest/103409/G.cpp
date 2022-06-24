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
int n;
char s[MAXN];

bool check(int mid) {
    ll now = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0')
            now++;
        else {
            if (now < mid)
                now = -mid;
            else if (now == mid)
                now = - max(0, mid - 1); //下一个点最大长度减一
            else
                return false;
        }
    }
    // 最后一段
    if (now > 0)
        return false;
    return true;
}

void solve() {
    n = read();
    scanf("%s", s + 1);
    int ans;
    int l = 0, r = n;
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

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}