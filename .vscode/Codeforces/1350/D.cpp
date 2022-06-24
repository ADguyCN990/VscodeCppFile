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
int n, k;
int a[MAXN];
int b[MAXN];
void solve() {
    n = read(), k = read();
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        if (a[i] == k) 
            flag = true;
    }
    if (!flag) {
        puts("NO");
        return;
    }
    if (n == 1 && flag) {
        puts("YES");
        return;
    }
    b[n + 1] = 0;
    b[n + 2] = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > k)
            b[i] = 2;
        else if (a[i] == k)
            b[i] = 1;
        else if (a[i] < k)
            b[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] > 0 && b[i + 1] > 0 || b[i] > 0 && b[i + 2] > 0) {
            puts("YES");
            return;
        }
    }
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