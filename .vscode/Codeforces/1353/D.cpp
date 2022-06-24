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
int n;
int ans[MAXN];
void solve() {
    n = read();
    priority_queue <pii> q;
    q.push({n, -1});
    for (int i = 1; i <= n; i++) {
        pii now = q.top();
        q.pop();
        int len = now.first;
        int l = -now.second, r = len + l - 1;
        int mid = (l + r) / 2;
        ans[mid] = i;
        if (l <= mid - 1)
            q.push({mid - l, -l});
        if (mid + 1 <= r)
            q.push({r - mid, -mid - 1});
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    puts("");
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}