#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 2005
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
int n, a, b;
string t = "abcdefghijklmnopqrstuvwxyz";
void solve() {
    n = read(), a = read(), b = read();
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cout << t[cnt++];
        if (cnt == b) cnt = 0;
    }
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