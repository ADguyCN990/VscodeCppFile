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
map<int, int> mp;
int n;

int get(int x) {
    if (x & 1) return x - 1;
    else return x + 1;
}

void solve() {
    mp.clear();
    n = read();
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        int x = read();
        mp[x] = 1;
        int to = get(x);
        if (mp[to]) flag = true;
    }
    if (flag)
        puts("Yes");
    else 
        puts("No");
}

int main() {
    int T = read();
    while (T--) {
        solve();
    }
    return 0;
}