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
ll a, k;
void solve() {
    a = read(), k = read();
    for (int i = 1; i < k; i++) {
        string s = to_string(a);
        sort(s.begin(), s.end());
        ll mn = s[0] - '0';
        ll mx = s[s.length() - 1] - '0';
        if (mn == 0) break;
        a += mn * mx;
        //printf("!!!%lld\n", a);
    }
    printf("%lld\n", a);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}