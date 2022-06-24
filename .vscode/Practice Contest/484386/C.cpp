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
ll n;
ll a[MAXN];
bitset <5000005> vis;//判断这个和之前有没有出现过
pair <int,int> ans[5000005];

void solve()
{
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int sum = a[i] + a[j];
            if (vis[sum] == 0) {
                ans[sum] = {i, j};
                vis[sum] = 1;
            }
            else if (vis[sum] == 1) {
                if (ans[sum].first != i && ans[sum].second != j && ans[sum].first != j && ans[sum].second != i) {
                    puts("YES");
                    printf("%d %d %d %d\n", ans[sum].first, ans[sum].second, i, j);
                    return;
                }
            }
        }
    }
    puts("NO");
}

int main() {
    solve();
    return 0;
}