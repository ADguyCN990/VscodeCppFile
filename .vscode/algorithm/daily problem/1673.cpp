#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
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

pii p[MAXN];
int n;
void solve() {
    n = read();
    for (int i = 1; i <= n; i++) {
        p[i].first = read();
        p[i].second = read();
    }
    sort(p + 1, p + 1 + n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                int x = p[i].first, y = p[i].second;
                int xx = p[j].first, yy = p[j].second;
                int a = p[k].first, b = p[k].second;
                if (x == xx && y != yy && x != a && y == b) {
                    ans = max(ans, abs(y - yy) * abs(x - a));
                }
                else if (x != xx && y == yy && x == a && y != b) {
                    ans = max(ans, abs(x - xx) * abs(y - b));
                }
                else if (x == xx && yy != y && xx != a && yy == b) {
                    ans = max(ans, abs(y - yy) * abs(xx - a));
                }
                else if (xx != x && yy == y && xx == a && yy != b) {
                    ans = max(ans, abs(x - xx) * abs(yy - b));
                }
                else if (a == xx && b != yy && a != x && b == y) {
                    ans = max(ans, abs(b - yy) * abs(a - x));
                }
                else if (a != xx && b == yy && a == x && b != y) {
                    ans = max(ans, abs(a - xx) * abs(b - y));
                }
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}