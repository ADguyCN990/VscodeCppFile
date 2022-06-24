#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
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
int a[MAXN];
int vis[MAXN];

int get() {
    for (int i = 0; i <= n; i++) vis[i] = 0;
    for (int i = 1; i <= n; i++) vis[a[i]] = 1;
    for (int i = 0; i <= n; i++) 
        if (!vis[i]) 
            return i;
}

void solve() {
    n = read();
    vector<int> ans;
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) {
        int mex = get();
        if (!mex) {
            bool flag = false;
            for (int j = 1; j <= n; j++) {
                if (a[j] != j) {
                    flag = true;
                    ans.pb(j);
                    a[j] = 0;
                    break;
                }
            }
            if (!flag)
                break;
            mex = get();
        }
        a[mex] = mex;
        ans.pb(mex);
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}