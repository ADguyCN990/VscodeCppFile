#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int, int> pii;
#define INF 1000000
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
int b[MAXN];
set<int> s;
bool check() {
    for (int i = 1; i <= n; i++) 
        if (a[i] > i)
            return false;
    return true;
}

void solve() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read(), b[i] = -1, s.insert(a[i]);
    bool flag = check();
    if (!flag) {
        puts("-1");
        return;
    }
    a[0] = -1;
    for (int i = 1; i <= n; i++)
        if (a[i] != a[i - 1])
            b[i] = a[i - 1];
    int now = 0;
    for (int i = 1; i <= n; i++) {
        if (b[i] != -1) continue;
        while (s.count(now)) 
            now++;
        b[i] = now;
        now++;
    }
    for (int i = 1; i <= n; i++) 
        printf("%d ", b[i]);
}

int main() {
    solve();
    return 0;
}