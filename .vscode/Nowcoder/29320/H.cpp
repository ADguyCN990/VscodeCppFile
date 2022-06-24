#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 15
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
pii p[MAXN];
vector<int> a;


void solve() {
    n = read(), k = read();
    for (int i = 1; i <= k; i++) p[i].first = read(), p[i].second = read();
    for (int i = 1; i <= k; i++) a.pb(i);
    int ans = INF;
    do {
        int cnt = 0;
        for (int i = 0; i < k - 1; i++) {
            int u = p[a[i]].first, v = p[a[i]].second;
            int uu = p[a[i + 1]].first, vv = p[a[i + 1]].second;
            cnt += 2 - (u == uu) - (u == vv) - (v == uu) - (v == vv);
        }
        ans = min(ans, cnt);
    }
        while (next_permutation(a.begin(), a.end()));
            
    printf("%d\n", ans + 4);
} 

int main() {
    solve();
    return 0;
}