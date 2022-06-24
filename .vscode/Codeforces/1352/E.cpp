#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 8005
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
bool vis[8000 * 8000 + 5];
void solve() {
    n = read();
    int sum = 0;
    for (int i = 1; i <= n; i++) a[i] = read(), sum += a[i];
    for (int i = 1; i <= sum; i++) vis[i] = false;
    for (int i = 1; i < n; i++) {
        sum = a[i];
        for (int j = i + 1; j <= n; j++) {
            sum += a[j];
            vis[sum] = true;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[a[i]]) 
            cnt++;
    }
    printf("%d\n", cnt);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}