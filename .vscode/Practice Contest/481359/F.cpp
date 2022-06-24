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

int get(string s) {
    int a = s[0] -  '0';
    int b = s[1] - '0';
    int c = s[3] - '0';
    int d = s[4] - '0';
    int x = (a * 10 + b);
    int y = c * 10 + d;
    return x * 60 + y;
}

void solve() {
    int n, k;
    n = read(), k = read();
    int all = 0;
    for (int i = 1; i <= n; i++) {
        string a, b;
        cin >> a >> b;
        all += get(b) - get(a);
    }
    if (all >= k * 60)
        puts("YES");
    else
        puts("NO");
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}