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

void solve() {
    vector<int> odd, even;
    int n = read();
    for (int i = 1; i <= n; i++) {
        int x = read();
        if (x & 1) odd.pb(x);
        else even.pb(x);
    }    
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    int mn = min(odd.size(), even.size());
    ll ans = 0;
    for (int i = 1; i <= mn; i++) {
        odd.pop_back();
        even.pop_back();
    }
    if (odd.size()) odd.pop_back();
    if (even.size()) even.pop_back();
    for (int i = 0; i < odd.size(); i++) ans += odd[i];
    for (int i = 0; i < even.size(); i++) ans += even[i];
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}