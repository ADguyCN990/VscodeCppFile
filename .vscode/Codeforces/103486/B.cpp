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
int a, b, k;
void solve() {
    a = read(), b = read(), k = read();
    int left = a / b;
    a = a % b;
    vector<int> ans;
    for (int i = 1; i <= k + 1; i++) {
        if (a < b) a *= 10;
        ans.pb(a / b);
        a %= b;
    }
    printf("%d.", left);
    for (int i = 0; i < k - 1; i++) printf("%d", ans[i]);
    if (ans[k] >= 5) printf("%d", ans[k - 1] + 1);
    else printf("%d", ans[k - 1]);
    puts("");
}

int main() {
    solve();
    return 0;
}